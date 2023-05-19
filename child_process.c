#include "main.h"
/**
 * child_process - executes the command found in the executable filr
 * @tokens:contains command and its arguments to be executed
 * @command_path:the path to the executable file
 * Return:void
 */
int child_process(char *command_path, char **tokens)
{
	int status;
	pid_t pid;
	int shell_interactive = isatty(STDIN_FILENO);

	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
		exit(1);
	}
	else if (pid == 0)
	{
		execve(command_path, tokens, environ);
		perror("execve failed");
		exit(1);
	}
	else
	{
		if (shell_interactive)
		{
			waitpid(pid, &status, 0);
		}
		if (WIFEXITED(status))
		{
			return (WEXITSTATUS(status));
		}
	}
	return (-1);
	/**
	 * check if the child process was successful or not
	 */
}

/**
 *
 *
 *
 *
 *
 */
void procfilecmd(char *file, __attribute__((unused))int shell_interactive)
{
	FILE *execfile;
	char *commandLine;
	size_t length;

	execfile = fopen(file, "r");

	if (execfile == NULL)
	{
		perror("Cannot open file");
		return;
	}

	commandLine = NULL;
	length = 0;
	while (_getline(&commandLine, &length, execfile) != -1)
	{
		commandLine[strcspn(commandLine, "\n")] = '\0';

		if (_strlen(commandLine) == 0)
			continue;
	}

	/*unfinished*/

	free(commandLine);
	fclose(execfile);
}
