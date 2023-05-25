#include "main.h"
/**
 * free_tokens - frees tokens
 * @tokens:tokens to be freed
 */
void free_tokens(char **tokens)
{
	int h;

	if (tokens == NULL)
	{
		return;
	}
	h = 0;
	for (h = 0; tokens[h] != NULL; h++)
	{
		free(tokens[h]);
	}
	free(tokens);
}
/**
 * _strdup - duplicates a string
 * @str:the string to be duplicated
 * Return:the duplicated string
 */
char *_strdup(char *str)
{
	int len;
	char *str_new;

	len = _strlen(str);

	if (str == NULL)
	{
		return (NULL);
	}
	str_new = (char *)malloc((len + 1) * sizeof(char));
	if (str_new == NULL)
	{
		return (NULL);
	}
	_strcpy(str_new, str);
	return (str_new);
}
/**
 * _strchr - locates a char in a string
 * @s:string comtaining the char
 * @c:the char to be found
 * Return:c
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	if (c == '\0')
	{
		return (s);
	}
	return (NULL);
}
/**
 * _strncpy - copies a string upto n bytes
 * @dest:dest pointer
 * @src:src pointer
 * @n:no of bytes to be copied
 * Return:a pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int input = 0;

	while (src[input] != '\0' && input < n)
	{
		dest[input] = '\0';
		input++;
	}
	return (dest);
}
/**
 * my_strchr - finds c in the input string s
 * @s:the string to find c
 * @c:the character to be found
 * Return:the found character
 */
char *my_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		s++;
	}
	return (NULL);
}

/**
 * my_putchar - writes character to stdout
 * @c: char to print
 * Return: 1(success), -1 otherwise, errno set appropriately
 */
int my_putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _putstr - prints string
 * @str: string to print
 * Return: characters printed
 */
int _putstr(char *str)
{
	int index = 0;

	while (str[index] != '\0')
	{
		my_putchar(str[index]);
		index++;
	}
	return (index);
}
