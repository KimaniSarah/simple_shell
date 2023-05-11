#include "main.h"

/**
 * exit_handler - handles arguments for the built-in exit
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

	exitStatus = atoi(arg[1]);

	exit(exitStatus);
}
