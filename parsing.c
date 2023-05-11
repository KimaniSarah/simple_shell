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

	token_size = TOKEN_BUFSIZE;
	tokens = malloc(token_size * sizeof(char *));
	if (tokens == NULL)
	{
		return (NULL);
	}
	token_pointer = strtok(command, TOKEN_SEPARATOR);
	index = 0;
	while (token_pointer != NULL)
	{
		tokens[index] = token_pointer;
	}
	tokens[index] = NULL;
	return (tokens);
}
