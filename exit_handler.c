#include "main.h"
/**
 * handle_exit - handle the inbuilt argument exit
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

	if (arg[1] == NULL)
	{
		printf("no argument found\n");
		return;
	}
	else if (arg[2] != NULL)
	{
		printf("excess arguments\n");
		return;
	}
	exitStatus = _atoi(arg[1]);
	exit(exitStatus);
}
/**
 * handle_env - handles the in-built env command
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
			while (*env != NULL)
			{
				printf("%s\n", *env);
				env++;
			}
		}
	}
}
