#include "main.h"

/**
 * set_env - Initializes a new envt var, modifies an existing one
 * prints something on stderr on failure
 *
 * @var: pointer to arguments passed to the function
 * Return: 0 on success, 1 otherwise
 */
int set_env(char **var)
{
	char printError[] = "Setenv Failed\n";

	if (var[1] == NULL || var[2] == NULL)
	{
		write(STDERR_FILENO, printError, sizeof(printError));
		return (1);
	}
	if (setenv(var[1], var[2], 1) != 0)
	{
		perror("error setting the environment variable");
		return (1);
	}

	return (0);
}

/**
 * unset_env - Removes an environment variable
 * prints something on stderr on failure
 *
 * @var: pointer to argument passed
 * Return: 0 on success, 1 on failure
 */
int unset_env(char **var)
{
	char Error[] = "Unsetenv Failed\n";

	if (var[1] == NULL)
	{
		write(STDERR_FILENO, Error, sizeof(Error));
		return (1);
	}

	if (unsetenv(var[1]) != 0)
	{
		perror("error removing the environment variable");
		return (1);
	}

	return (0);
}
