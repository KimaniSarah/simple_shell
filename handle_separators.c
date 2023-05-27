#include "main.h"
/**
 * get_separators - gets what separated the commands
 * @command:the string to findthe separator in
 * Return:the separators
 */
char **get_separators(char *command)
{
	int len, h, v, z;
	char **separators;
	char sep[4] = "";

	v = 0;
	h = 0;
	len = _strlen(command);
	separators = (char **)malloc((len + 1) * sizeof(char *));
	if (separators == NULL)
		return NULL;

	for (z = 0; z < len; z++)
	{
		if (command[z] == ';' || command[z] == '|' || command[z] == '&')
		{
			if (v > 0)
			{
				sep[v] = '\0';
				separators[h] = _strdup(sep);
				if (separators[h] == NULL)
				{
					free_tokens(separators);
					return (NULL);
				}
				h++;
				v = 0;
			}
			sep[v] = command[z];
			v++;
			if (z + 1 < len && command[z + 1] == command[z])
			{
				sep[v] = command[z + 1];
				v++;
				z++;
			}
		}
	}
	if (v > 0)
	{
		sep[v] = '\0';
		separators[h] = _strdup(sep);
		if (separators[h] == NULL)
		{
			free_tokens(separators);
			return (NULL);
		}
		h++;
	}
	separators[h] = NULL;
	return (separators);
}
/**
 * handle_separators - separate commands according to present delimiter
 * @command:the command to separeate
 * Return:the separated commands
 */
char **handle_separators(char *command)
{
	char **commands, *token, *command_now;
	int count;
	int command_num, separators, h;
	tokenise str;

	separators = 0;
	command_now = _strdup(command);
	if (command_now == NULL)
	{
		return (NULL);
	}
	for (h = 0; command_now[h]; h++)
	{
		if (command_now[h] == ';' || command_now[h] == '|' || command_now[h] == '&')
		{
			separators++;
		}
	}
	command_num = separators + 1;
	commands = malloc(sizeof(char *) * (command_num + 1));
	if (commands == NULL)
	{
		free(command_now);
		return (NULL);
	}
	count = 0;
	token = _strtok(&str, command_now, ";&|");
	while (token != NULL && count < command_num)
	{
		commands[count] = _strdup(token);
		count++;
		token = _strtok(&str, NULL, ";&|");
	}
	commands[count] = NULL;
	free(command_now);
	return (commands);
}

