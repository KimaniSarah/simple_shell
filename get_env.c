#include "main.h"
/**
 * _getenv - gets environment
 * @name:
 * Return:the env
 */
char *_getenv(char *name)
{
	int len = _strlen(name);
	char **env_var = environ;

	while(env_var != NULL)
	{
		if(_strncmp(name, *env_var, len) == 0 && (*env_var)[len] == '=')
		{
			return &((*env_var)[len + 1]);
		}
		env_var++;
	}
	return (NULL);
}
