#include "main.h"
/**
 * exit - handle the inbuilt argument exit
 * @tokens: arguments passed
 * Return:void
 */
void handle_exit(char **tokens)
{
	if (tokens != NULL)
	{
		if (_strcmp(tokens[0], "exit") == 0)
		{
			exit(0);
		}
	}
}
/**
 * exit_handler - handles arguments for the built-in exit with arguments
 *
 * @arg: argument passed to the function
 */
void exit_handler(char **arg)
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
/**
 * env_handler - handles the in-built env command
 * @tokens:the arguments passed
 * Return:void
 */
void handle_env(char **tokens)
{
	char **env = environ;

	if (tokens != NULL)
	{
		if (_strcmp(tokens[0], "env") == 0)
		{
			for(;*env != NULL; env++)
			{
				printf("%s\n", *env);
			}
		}
	}
}
