#include "main.h"
int main(__attribute__((unused))int argc, char **argv)
{
	int h;
	char *command, *command_path;
	size_t bufsize;
	char **commands;

	bufsize = BUF_SIZE;
	command = (char *)malloc(bufsize * sizeof(char));
	if (command == NULL)
	{
		perror("malloc failed");
		exit(1);
	}
	while(1)
	{
		if (isatty(STDIN_FILENO))
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
			for (h = 0; commands[h] != NULL; h++)
			{
				argv = parse_line(commands[h]);
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
