#include "main.h"
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
