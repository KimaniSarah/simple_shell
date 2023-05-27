#include "main.h"

/**
 * add_path - adds path to command
 * @command_path: path of the command
 * @inputstr: the cmd string entered by user
 * Return: buffer holding command with path, NULL otherwise
 */
char *add_path(char *command_path, char *inputstr)
{
	char *buffer;
	size_t index = 0, i = 0;

	if (inputstr == 0)
		inputstr = " ";
	if (command_path == 0)
		command_path = " ";

	buffer = malloc(sizeof(char) *
			(_strlen(command_path) + _strlen(inputstr) + 2));
	if (!buffer)
		return (NULL);
	while (command_path[index])
	{
		buffer[index] = command_path[index];
		index++;
	}
	if (command_path[index - 1] != '/')
	{
		buffer[index] = '/';
		index++;
	}
	while (inputstr[i])
	{
		buffer[index + i] = inputstr[i];
		i++;
	}
	buffer[index + i] = '\0';
	/*free(buffer);*/
	return (buffer);
}

/**
 * path_validate - checks if the path exists
 * @path: the tokenized path
 * @inputstr: user input command
 * Return: command appended path (success), NULL on failure
 */
char *path_validate(char **path, char *inputstr)
{
	int index = 0;
	char *ret;

	while (path[index])
	{
		ret = add_path(path[index], inputstr);
		if (access(ret, F_OK | X_OK) == 0)
			return (ret);
		free(ret);
		index++;
	}
	return (NULL);
}

/**
 * get_path - gets path from environ
 * Return: the path, or NULL if path not found
 */
char *get_path(void)
{
	int index;
	char **env = environ;
	char *cmd_path = NULL;

	while (*env)
	{
		if (_strncmp(*env, "PATH=", 5) == 0)
		{
			cmd_path = *env;
			while (*cmd_path && index < 5)
			{
				cmd_path++;
				index++;
			}
			return (cmd_path);
		}
		env++;
	}
	return (NULL);
}
