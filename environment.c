#include "main.h"
/**
 * _setenv - initializes a new envt var, or modifies an existing one
 *
 * @name: name of the environment variable
 * @value: value to be set for the environment variable
 * @overwrite: flag indicating whether to overwrite an existing var
 * Return: 0 on Success, -1 on failure
 */
int _setenv(char *name, char *value, int overwrite)
{
	char **environ_ptr, **new_environ;
	int index, position = 0;
	char *var, *setenvError = "Invalid name or value.\n";
	size_t name_length, value_length, var_length;

	if (!name || !*name || strchr(name, '=') || !value)
	{
		write(STDERR_FILENO, setenvError, _strlen(setenvError));
		return (-1);
	}
	if (!overwrite && _getenv(name) != NULL)
		return (0);
	name_length = _strlen(name);
	value_length = _strlen(value);
	var_length = name_length + value_length + 2;
	var = (char *)malloc(var_length);
	if (var == NULL)
		return (-1);
	strncpy(var, name, name_length);
	var[name_length] = '=';
	strncpy(var + name_length + 1, value, value_length);
	var[var_length - 1] = '\0';
	environ_ptr = environ;
	while (*environ_ptr != NULL)
	{
		if (strncmp(*environ_ptr, name, name_length) == 0 &&
				(*environ_ptr)[name_length] == '=')
		{
			break;
		}
		++position;
		++environ_ptr;
	}
	new_environ = (char **)malloc((position + 2) * sizeof(char *));
	if (new_environ == NULL)
	{
		free(var);
		return (-1);
	}
	for (index = 0; index < position; ++index)
	{
		new_environ[index] = *environ_ptr;
		++environ_ptr;
	}
	new_environ[index] = var;
	new_environ[index + 1] = NULL;
	environ = new_environ;
	return (0);
}
/**
 * _unsetenv - removes an environment variable
 *
 * @name: name of the environment variable
 * Return: 0 on Success, -1 on failure
 */
int _unsetenv(char *name)
{
	char **environ_ptr;
	int position = 0;
	char *unsetenvError = "Invalid name.\n";

	if (name == NULL || !*name || strchr(name, '='))
	{
		write(STDERR_FILENO, unsetenvError, _strlen(unsetenvError));
		return (-1);
	}

	environ_ptr = environ;

	while (*environ_ptr != NULL)
	{
		if (strncmp(*environ_ptr, name, _strlen(name)) == 0 &&
					(*environ_ptr)[_strlen(name)] == '=')
		{
			break;
		}
		++position;
		++environ_ptr;
	}
	if (*environ_ptr == NULL)
		return (0);
	while (environ_ptr[1] != NULL)
	{
		environ_ptr[0] = environ_ptr[1];
		++environ_ptr;
	}
	free(*environ_ptr);
	*environ_ptr = NULL;

	return (0);
}
