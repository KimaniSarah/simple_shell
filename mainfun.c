#include "main.h"
int main(__attribute__((unused))int ac, __attribute__((unused))char **av)
{
	int h;
	char *command;
	char **tokens;
	char *command_path;
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
			tokens = parse_line(commands[h]);
			if (_strcmp(tokens[0], "exit") == 0)
			{
				if (tokens[1] != NULL)
				{
					exit_handler(tokens);
				}
				else
				{
					handle_exit(tokens);
				}
			}
			else if (_strcmp(tokens[0], "env") == 0)
			{
				handle_env(tokens);
			}
			else if (_strcmp(tokens[0], "cd") == 0)
			{
				change_directory(tokens);
			}
			else
			{
				command_path = find_executable(tokens);
				child_process(command_path, tokens);
			}
			/*free_tokens(tokens);*/
			free(command_path);
		}
		free_tokens(commands);
	}
	free(command);
	return (0);
}
