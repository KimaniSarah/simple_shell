#include "main.h"
/**
 * handle_separators - to separate commands separated by ;
 * @command:the commands to be separated
 * Return:pointer to a buffer containing the separated commands
 */
char **handle_separators(char *command)
{
	char **commands;
	char *token;
	int count;
	int h, v;
	int command_num;
	char *command_now;

	command_now = strdup(command);
	if (command_now == NULL)
	{
		return (NULL);
	}

	command_num = 0;
	for (h = 0; command_now[h]; h++)
	{
		if (command_now[h] == ';')
		{
			command_num++;
		}
	}
	command_num++;
	/**
	 * to count the number of commands present
	 */
	commands = malloc(sizeof(char *) * command_num);
	/**
	 * just space for pointers to th commands
	 */
	if (commands == NULL)
	{
		free(command_now);
		return (NULL);
	}
	count = 0;
	token = strtok(command_now, ";");
	while(token != NULL && count < command_num)
	{
		commands[count] = strdup(token);
		count++;
		token = strtok(NULL, ";");
	}
	for (v = count; v < command_num; v++)
	{
		free(commands[v]);
	}
	/**
	 * free unused memory
	 */
	free(command_now);
	commands[count] = NULL;
	return (commands);
}
