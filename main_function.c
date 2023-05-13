#include "main.h"
int main(void)
{
	char *command;
	char **tokens;
	char *command_path;
	size_t bufsize;

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
		command = read_line();
		if (feof(stdin))
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
	tokens = parse_line(command);
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
		continue;
	}
	if (_strcmp(tokens[0], "env") == 0)
	{
		handle_env(tokens);
		continue;
	}
	command_path = find_executable(tokens);
	child_process(command_path, tokens);
	free(command);
	free(tokens);
	free(command_path);
	}
	free(command);
	return (0);
}
