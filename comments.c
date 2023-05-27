#include "main.h"
/**
 * remove_comments - it removes comments
 * @command:the command to remove the comment
 */
void remove_comments(char *command)
{
	char *comment_pos;
	int command_length;

	comment_pos = _strchr(command, '#');
	if (comment_pos != NULL)
	{
		*comment_pos = '\0';
	}
	command_length = _strlen(command);
	while (command_length > 0 && command[command_length - 1] == ' ')
	{
		command[command_length - 1] = '\0';
		command_length--;
	}
}
