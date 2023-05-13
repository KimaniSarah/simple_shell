#include "main.h"
/**
 * find_executable - find executable file with matching name from tokens
 * @tokens:contain the command and arguments
 * Return:the path to the executable file
 */
char *find_executable(char **tokens)
{
	char *path;
	char *token;
	char *command_path;

	path = _getenv("PATH");
	if (path == NULL)
	{
		return (NULL);
	}
	token = strtok(path, ":");
	while (token != NULL)
	{
		command_path = malloc(_strlen(token) * _strlen(tokens[0]) + 2);
		/**
		 * +2 coz of the backslash and '\0'char
		 */
		if (command_path == NULL)
		{
			return (NULL);
		}
		_strcpy(command_path, token);
		_strcat(command_path, "/");
		_strcat(command_path, tokens[0]);
		if (access(command_path, F_OK) == 0)
		{
			break;
		}
		free(command_path);
		command_path = NULL;
		token = strtok(NULL, ":");
	}
	if (command_path == NULL)
	{
		perror("no such file");
		exit(1);
	}
	return (command_path);
}
