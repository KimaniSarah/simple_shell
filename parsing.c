#include "main.h"
/**
 * parse_line - parses and tokenise the read command and its arguments
 * @command:the command to be tokenised
 * Return:a pointer to an array of pointers containing the tokenised command
 */
char **parse_line(char *command)
{
	int tokens_max;
	int index;
	char **tokens, **tokens_new;
	tokenise str;
	char *token_pointer;
	char *command_now;

	tokens_max = 4;
	command_now = _strdup(command);
	if (command_now == NULL)
	{
		return (NULL);
	}
	tokens = malloc(tokens_max * sizeof(char *));
	if (tokens == NULL)
	{
		free(command_now);
		return (NULL);
	}
	token_pointer = _strtok(&str, command_now, TOKEN_SEPARATOR);
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
		if (index >= tokens_max)
		{
			tokens_max *= 2;
			tokens_new = realloc(tokens, sizeof(char *) * tokens_max);
			if (tokens_new == NULL)
			{
				free(command_now);
				free_tokens(tokens);
				return (NULL);
			}
			tokens = tokens_new;
		}
		token_pointer = _strtok(&str, NULL, TOKEN_SEPARATOR);
	}
	tokens[index] = NULL;
	free(command_now);
	return (tokens);
}
