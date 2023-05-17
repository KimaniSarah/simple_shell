#include "main.h"
/**
 * parse_line - parses and tokenise the read command and its arguments
 * @command:the command to be tokenised
 * Return:a pointer to an array of pointers containing the tokenised command
 */
char **parse_line(char *command)
{
	int token_size;
	int index;
	char **tokens;
	char *token_pointer;
	char *command_now;

	token_size = TOKEN_BUFSIZE;
	command_now = _strdup(command);
	if (command_now == NULL)
	{
		return (NULL);
	}
	tokens = malloc(token_size * sizeof(char *));
	if (tokens == NULL)
	{
		free(command_now);
		return (NULL);
	}
	token_pointer = strtok(command_now, TOKEN_SEPARATOR);
	index = 0;
	while (token_pointer != NULL)
	{
		tokens[index] = _strdup(token_pointer);
		if (tokens[index] == NULL)
		{
			free_tokens(tokens);
			free(command_now);
			return (NULL);
		}
		index++;
		token_pointer = strtok(NULL, TOKEN_SEPARATOR);
	}
	tokens[index] = NULL;
	free(command_now);
	return (tokens);
}
