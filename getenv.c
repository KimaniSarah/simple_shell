#include "main.h"

/**
 * _getenv - gets the value of the environment variable
 * @name: the name of the varibale we want to find its value
 * Return: value of the env variable
 */
char *_getenv(char *name)
{
	char **env_variables;
	int name_length;

	env_variables = environ;
	name_length = _strlen(name);

	while (env_variables != NULL)
	{
		if (_strncmp(*env_variables, name, name_length) == 0 &&
				(*env_variables)[name_length] == '=')
		{
			return (&((*env_variables)[name_length + 1]));
		}
		env_variables++;
	}
	return (NULL);
}
