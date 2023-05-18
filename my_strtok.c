#include "main.h"
/**
 * tokenise_str - initialize tokenise structure by setting last_token to null
 * @str:used to initialise last_token
 * Return:void
 */
void tokenise_str(tokenise *str)
{
	str->last_token = NULL;
}
/**
 * _strtok - retrive the next token from the input string
 * @str:struct pointer
 * @string:the string to tokenise
 * @delimiter:the separator
 * Return:the token retrived
 */
char *_strtok(tokenise *str, char *string, const char *delimiter)
{
	char *current_token;
	char *end_token;

	if (string != NULL)
	{
		str->last_token = string;
	}
	if (string == NULL && str->last_token == NULL)
	{
		return (NULL);
	}
	current_token = str->last_token;
	if (*current_token == '\0')
	{
		str->last_token = NULL;
		return (NULL);
	}
	end_token = current_token;
	while (*end_token != '\0' && my_strchr(delimiter, *end_token) == NULL)
	{
		end_token++;
	}
	/**
	 * move end_token until the delimiter is found
	 */
	if (*end_token == '\0')
	{
		str->last_token = NULL;
	}
	else
	{
		*end_token = '\0';
		str->last_token = end_token + 1;
	}
	return (current_token);
}
