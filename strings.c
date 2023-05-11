#include "main.h"
/**
 * _strcmp - compares two strings
 *
 * @s1: first string to be compared
 * @s2: second string to be compared
 * Return: If str1 < str2, a negative integer value
 *		 If str1 == str2, 0
 *		 If str1 > str2, a positive integer value
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
#include "main.h"
/**
 * _strncpy - Copies at most an inputted number
 * of bytes from string src into dest
 *
 * @dest: the string copy
 * @src: The source string
 * Return: a pointer to dest
 */
char *_strncpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
#include "main.h"
/**
 * _strcat - Concatenates the string pointed to by @src, including the
 * null byte, to the end of the string pointed to by @dest.
 * @dest: pointer to the string to be concatenated upon.
 * @src: source string to be appended to @dest.
 *
 * Return: A pointer to the destination string @dest.
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
#include "main.h"
/**
 * _strlen - returns the length of a string
 *
 * @s: string length to be checked
 * Return: length of a string
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
