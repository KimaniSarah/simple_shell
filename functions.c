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
