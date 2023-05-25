#include "main.h"

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
