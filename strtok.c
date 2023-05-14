#include "main.h"

/**
 * length_of_token - to find token length
 *
 * @s: string holding the command
 * @delimiter: the delimiter
 * Return: toekn length
 */
int length_of_token(char *s, char *delimiter)
{
	int elem = 0;
	int length = 0;

	while (*(s + elem) && *(s + elem) != *delimiter)
	{
		length++;
		elem++;
	}
	return (length);
}

/**
 * token_count - count tokens
 *
 * @s: string holding command
 * @delimiter: delimiter
 * Return: characters in string holding command
 */
int token_count(char *s, char *delimiter)
{
	int elem = 0;
	int token = 0;
	int length = 0;

	for (elem = 0, *(s + elem); elem++)
	{
		if (*(s + elem) != *delimiter)
		{
			token++;
			elem += length_of_token(s + elem, delimiter);
		}
	}

	return (token);
}

/**
 * _strtok - tokenizes command string
 *
 * @cmdInput: the command string
 * @delimiter: delimiter used to tokenize string
 * Return: pointer to tokenized string
 */
char **_strtok(char *cmdInput, char *delimiter)
{
	char **lineptr;
	int i = 0;
	int total_tokens, index, chars, elem;

	total_tokens = token_count(cmdInput, delimiter);

	if (total_tokens == 0)
		return (NULL);

	lineptr = malloc(sizeof(char *) * (total_tokens + 2));
	if (lineptr == NULL)
		return (NULL);

	for (index = 0; index < total_tokens; index++)
	{
		while (cmdInput[i] == *delimiter)
			i++;

		chars = length_of_token(cmdInput + i, delimiter);

		lineptr[index] = malloc(sizeof(char) * (chars + 1));
		if (!lineptr[index])
		{
			for (i -= 1; i >= 0; i--)
				free(lineptr[i]);
			free(lineptr);
			return (NULL);
		}
		for (elem = 0; elem < chars; elem++)
		{
			lineptr[index][elem] = cmdInput[i];
			i++;
		}
		lineptr[index][elem] = '\0';
	}

	lineptr[index] = NULL;
	lineptr[index + 1] = NULL;

	return (lineptr);
}
