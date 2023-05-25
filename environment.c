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
