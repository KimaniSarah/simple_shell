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

	for (;str[elem] != '\0'; elem++)
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
 * my_realloc - 
