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
 * @oldSize: size of previously allocated memory
 * Return: a void pointer to newly allocated memory
 */
void *_realloc(void *oldPtr, int oldSize, int size)
{
	void *memory;
	char *oldPtr_copy, *newPtr;
	int elem;

	if (size == oldSize)
		return (oldPtr);

	if (oldPtr == NULL)
	{
		memory = malloc(size);
		if (memory == NULL)
			return (NULL);

		return (memory);
	}

	if (size == 0 && oldPtr != NULL)
	{
		free(oldPtr);
		return (NULL);
	}

	oldPtr_copy = oldPtr;
	memory = malloc(sizeof(*oldPtr_copy) * size);
	if (memory == NULL)
	{
		free(oldPtr);
		return (NULL);
	}

	newPtr = memory;

	for (elem = 0; elem < oldSize && elem < size; elem++)
	{
		newPtr[elem] = *oldPtr_copy++;
	}
	free(oldPtr);
	return (memory);
}
