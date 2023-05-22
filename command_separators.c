#include "main.h"
/**
 * handle_separators - to separate commands separated by ;
 * @command:the commands to be separated
 * Return:pointer to a buffer containing the separated commands
 */
char **handle_separators(char *command)
{
	char **commands, *token, *command_now;
	int count;
	int command_num, separators, h, v;
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
	commands = malloc(sizeof(char *) * command_num);
	if (commands == NULL)
	{
		free(command_now);
		return (NULL);
	}
	count = 0;
	/*token = strtok(command_now, ";&|");*/
	token = _strtok(&str, command_now, ";&|");
	while (token != NULL && count < command_num)
	{
		commands[count] = _strdup(token);
		count++;
		/*token = strtok(NULL, ";&|");*/
		token = _strtok(&str, NULL, ";&|");
	}
	for (v = count; v < command_num; v++)
	{
		free(commands[v]);
	}
	free(command_now);
	commands[count] = NULL;
	return (commands);
}
