#include "main.h"
/**
 * _strcmp - compares 2 strings
 * @s2: 1st string to be compared
 * @s1: 2nd string to be compared
 * Return: if s1<s2, a -ve int value
 * if s1 == s2 , 0
 * if s1 >s2, +ve int value
 */
int _strcmp(char *s1, char *s2)
{
	int x = 0;

	while (s1[x] == s2[x])
	{
		if (s1[x] == '\0')
		{
			return (0);
		}
		x++;
	}
	return (s1[x] - s2[x]);
}
/**
 * _strcpy - copies the string src into dest
 * @dest:the pointer to be copied into
 * @src:the pointer to copy
 * Return:the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	char *start = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (start);
}
/**
 * _strcat - conc the string pointed to by src
 * @dest:pointer to the styring to be conc upon
 * @src:source string to be appended to the dest string
 * Return:a pointer to the dest string
 */
char *_strcat(char *dest, char *src)
{
	char *res = dest;

	while (*res != '\0')
	{
		res++;
	}
	while (*src != '\0')
	{
		*res++ = *src++;
	}
	*res = '\0';
	return (dest);
}
/**
 * _strlen - return the length of a string
 * @s:string length to be checked
 * Return:length of a string
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}
/**
 * _strncmp - compare 2 strings upto n bytes
 * @s1:the pointer to the 1st to be compared
 * @s2:the pointer to the 2nd string to be compred
 * @n:the max no pof chars to be compared
 * Return:if successful 0, if s1>s2, +ve int value
 * if s1<s2, -ve int value
 */
int _strncmp(char *s1, char *s2, int n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
		{
		return (*s1 - *s2);
		}
	if (*s1 == '\0')
	{
	return (0);
	}
	s1++;
	s2++;
	n--;
	}
	return (0);
}
/**
 * free_tokens - frees tokens
 * tokens:tokens to be freed
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
 * @s:string potentially comtaining the char
 * c:the char to be located
 * Return:c, NULL if char is not found
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
 * @dest:the destination pointer
 * @src:the source pointer
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
