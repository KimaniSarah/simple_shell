#include "main.h"
/**
 * _getenv - get the value of the enviroment variable
 * @name: the name of the variable we want to find its value
 * Return:value of the env variable
 */
char *_getenv(char *name)
{
	char **env_variables;
	int name_length;

	env_variables = environ;
	name_length = _strlen(name);

	while (env_variables != NULL)
	{
		if (_strncmp(*env_variables, name, name_length) == 0 && (*env_variables)[name_length] == '=')
		{
			return &((*env_variables)[name_length + 1]);
		}
		env_variables++;
	}
	return (NULL);
}
