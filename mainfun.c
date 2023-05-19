#include "main.h"
int main(__attribute__((unused))int argc, char *argv[])
{
	int index;
	char *command, *command_path;
	size_t bufsize;
	char **commands;
	int shell_interactive;

       	shell_interactive = isatty(STDIN_FILENO) ? 1 : 0;

	bufsize = BUF_SIZE;
	command = (char *)malloc(bufsize * sizeof(char));
	if (command == NULL)
	{
		perror("malloc failed");
		exit(1);
	}
	while(1)
	{
		if (shell_interactive)
		{
			print_prompt();
			fflush(stdout);
			command = read_line();
			if (feof(stdin))
			{
				write(STDOUT_FILENO, "\n", 1);
				break;
			}
			commands = handle_separators(command);
			for (index = 0; commands[index] != NULL; index++)
			{
				argv = parse_line(commands[index]);
				if (_strcmp(argv[0], "exit") == 0)
				{
					if (argv[1] != NULL)
					{
						exit_handler(argv);
					}
					else
					{
						handle_exit(argv);
					}	
				}
				else if (_strcmp(argv[0], "env") == 0)
				{
					handle_env(argv);
				}
				else if (_strcmp(argv[0], "cd") == 0)
				{	
					change_directory(argv);
				}
				else
				{
					command_path = find_executable(argv);
					child_process(command_path, argv);
				}
				free(command_path);
			}
			free_tokens(commands);
		}
	}
	free(command);
	return (0);
}
