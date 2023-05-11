#include "main.h"
/**
 * child_process - executes the command found in the executable filr
 * @tokens:contains command and its arguments to be executed
 * @command_path:the path to the executable file
 * Return:void
 */
void child_process(char *command_path, char **tokens)
{
	pid_t pid;

	pid = fork();

	if (pid < 0)
	{
		perror("fork failed");
		exit(1);
	}
	else if (pid == 0)
	{
		execve(command_path, tokens, NULL);
		perror("execve failed");
		exit(1);
	}
	else
	{
		wait(NULL);
	}
}
