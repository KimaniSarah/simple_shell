#include "main.h"

/**
 * _atoi - converts a string into an integer
 *
 * @str: input string
 * Return: Integer
 */
int _atoi(char *str)
{
	int res = 0;
	int sign = 1;
	int elem = 0;

	if (str[0] == '-')
	{
		sign = -1;
		elem++;
	}

	for (; str[elem] != '\0'; elem++)
	{
		if (str[elem] >= '0' && str[elem] <= '9')
		{
			res = res * 10 + (str[elem] - '0');
		}
		else
		{
			break;
		}
	}
	return (res * sign);
}

/**
 * _memcpy - copies memory from one memory area to another
 *
 * @dest: the memory area to copy bytes to
 * @src: the memory area to copy bytes from
 * @size: size of bytes to copy
 * Return: a pointer to the destination
 */
char *_memcpy(char *dest, char *src, size_t size)
{
	unsigned int bytes = 0;

	for (bytes = 0; bytes < size; bytes++)
	{
		dest[bytes] = src[bytes];
	}

	return (dest);
}

/**
 * _realloc - reallocates memory to increase buffer size
 *
 * @oldPtr: pointer to old block of memory
 * @size: memory size to allocate
 * Return: a void pointer to newly allocated memory
 */
void *_realloc(void *oldPtr, size_t size)
{
	void *newPtr = malloc(size);

	if (newPtr == NULL)
		return (NULL);

	if (oldPtr != NULL)
	{
		_memcpy(newPtr, oldPtr, size);
		free(oldPtr);
	}

	return (newPtr);
}
