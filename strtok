#include "main.h"

/**
 * _strtok - tokenizes command string
 *
 * @cmdInput: the command string
 * @delimiter: delimiter used to tokenize string
 * Return: pointer to tokenized string
 */
char *_strtok(char *cmdInput, char *delimiter)
{
	static char *pos;
	char *next_token;
	int index = 0;

	if (!cmdInput || !*cmdInput)
	{
		if (!pos || !*pos)
			return (NULL);
		while (_strcmp(pos + index, delimiter) != 1 && *(pos + index) != '\0')
		{
			index++;
		}
		if (*(pos + index) == '\0')
		{
			pos = NULL;
			return (pos);
		}

		next_token = pos;

		*(pos + index) = '\0';
		pos = pos + index + _strlen(delimiter);
		return (next_token);
	}
	while (_strcmp(cmdInput + index, delimiter) != 1 && *(cmdInput + index) != '\0')
	{
		index++;
	}
	if (*(cmdInput + index) == '\0')
	{
		return (cmdInput);
	}
	pos = cmdInput + index + _strlen(delimiter);
	*(cmdInput + index) = '\0';

	return (cmdInput);
}
