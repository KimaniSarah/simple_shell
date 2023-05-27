#include "main.h"
/**
 * main - Entry point
 * @argc: argument count
 * @argv: pointer to array of arguments
 * Return: 0 (Success)
 */
int main(__attribute__((unused))int argc, char *argv[])
{
	char *cmdline = NULL, *command_path = NULL, *findpath = NULL;
	char **token = NULL, **pathptr = NULL;
	size_t buffersize = 0;
	ssize_t size = 0;

	signal(SIGINT, sign_handler);
	while (1)
	{
		frees_buf(token);
		frees_buf(pathptr);
		free(command_path);
		prompt();
		fflush(stdout);
		size = getline(&cmdline, &buffersize, stdin);
		if (size < 0)
			break;
		remove_comments(cmdline);
		if (cmdline[size - 1] == '\n')
			cmdline[size - 1] = '\0';
		token = parse_line(cmdline);
		if (token == NULL || *token == NULL || **token == '\0')
			continue;
		if (_strcmp(token[0], "cd") == 0)
		{
			change_d(token[1]);
			continue;
		}
		if (checks_builtin(token, cmdline))
			continue;
		findpath = get_path();
		pathptr = parse_line(findpath);
		command_path = path_validate(pathptr, token[0]);
		if (!command_path)
			perror(argv[0]);
		else
			execute(command_path, token);
	}
	if (size < 0 && shell.modeInteractive)
		write(STDERR_FILENO, "\n", 1);
	free(cmdline);
	return (0);
}
