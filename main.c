#include "main.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: pointer to array of arguments
 * Return: 0 (Success)
 */
int main(int argc, char *argv[])
{
	char *cmdline = NULL, *command_path = NULL, *findpath = NULL;
	char **token = NULL, **pathptr = NULL;
	size_t buffersize = 0;
	ssize_t size = 0;
	const char *old_dir;
	const char *home_dir;
	char current_path[MAX_PATH_LENGTH];

	if (argc < 1)
		return (-1);
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
		if (cmdline[size - 1] == '\n')
			cmdline[size - 1] = '\0';
		token = parse_line(cmdline);
		if (token == NULL || *token == NULL || **token == '\0')
			continue;
		if (_strcmp(token[0], "cd") == 0)
		{
			if(token[1] == NULL)
			{
				home_dir = _getenv("HOME");
				if (home_dir == NULL)
				{
					perror("error");
					continue;
				}
				if (chdir(home_dir) != 0)
				{
					perror("chdir() error");
					continue;
				}
			}
			else if (_strcmp(token[1], "-") == 0)
			{
				old_dir = _getenv("OLDPWD");
				if (old_dir == NULL)
				{
					perror("error");
					continue;
				}
				if (chdir(old_dir) != 0)
				{
					perror("chdir() error");
					continue;
				}
			}
			else
			{
				if (chdir(token[1]) != 0)
				{
					perror("chdir() error");
					continue;
				}
			}
			if (getcwd(current_path, sizeof(current_path)) == NULL)
			{
				perror("getcwd() error");
				continue;
			}
			if (setenv("PWD", current_path, 1) != 0)
			{
				perror("setenv() error");
				continue;
			}
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
