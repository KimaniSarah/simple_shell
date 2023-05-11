#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

define BUF_SIZE 1024

/**
 * get_line - function that reads what user types
 *
 * Return: command string
 */
char *get_line(void)
{
	static char buffer[BUF_SIZE];
	static int position_at_buffer, end_of_buffer;
	char *command;
	int cl_position;

	if (position_at_buffer >= end_of_buffer)
	{
		end_of_buffer = read(STDIN_FILENO, buffer, BUF_SIZE);
		position_at_buffer = 0;
		if (end_of_buffer == 0)
			return (NULL);
		if (end_of_buffer == -1)
		{
			perror("get_line fail");
			return (NULL);
		}
	}
	command = malloc(BUF_SIZE);
	cl_position = 0;

	while (postion_at_bufer < end_of_buffer)
	{
		if (buffer[position_at_buffer] == '\n')
		{
			command[cl_position] = '\0';
			position_at_buffer++;
			return (command);
		}
		command[cl_position] = buffer[position_at_buffer];
		cl_position++;
		position_at_buffer++;
		if (position_at_buffer >= end_of_buffer)
			break;
	}
	if (end_of_buffer == 0)
		return (NULL);
	if (cl_position >= BUF_SIZE)
		command = realloc(command, cl_position + 1);
	command[cl_position] = '\0';
	return (command);
}
