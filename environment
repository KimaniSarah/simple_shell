#include "main.h"

/**
 * handle_env - prints environ string to stdout
 *
 */
void handle_env(void)
{
	int index = 0;
	char **envt = environ;

	while (envt[index])
	{
		write(STDOUT_FILENO, (const void *)envt[index], _strlen(envt[index]));
		write(STDOUT_FILENO, "\n", 1);
		index++;
	}
}

/**
 * exit_argument - handles argument for exit with argument
 * @arg: argument passed to the function
 */
void exit_argument(char **arg)
{
	int exitStatus;
	char *argError = "no argument found\n";
	char *exitErr = "excess arguments\n";

	if (arg[1] == NULL)
	{
		write(STDERR_FILENO, argError, _strlen(argError));
		return;
	}
	else if (arg[2] != NULL)
	{
		write(STDERR_FILENO, exitErr, _strlen(exitErr));
		return;
	}
	exitStatus = _atoi(arg[1]);
	exit(exitStatus);
}
