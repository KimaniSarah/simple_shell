#include "main.h"

/**
 * reassign_cmdptr - reassigns cmdptr variable
 *
 * @cmdptr: buffer to store input string
 * @cmdptr_size: size of cmdptr
 * @buffer: string to assign
 * @size: size of buffer
 */
void reassign_cmdptr(char **cmdptr, size_t *cmdptr_size, char *buf,
		size_t size)
{
	if (*cmdptr == NULL)
	{
		if (size > 120)
			*cmdptr_size = size;
		else
			*cmdptr_size = 120;
		*cmdptr = buf;
	}
	else if (*cmdptr_size < size)
	{
		if (size > 120)
			*cmdptr_size = size;
		else
			*cmdptr_size = 120;
		*cmdptr = buf;
	}
	else
	{
		_strcpy(*cmdptr, buf);
		free(buf);
	}
}

/**
 * _getline - reads stream input
 * @cmdptr: bufer to store input string
 * @cmdptr_size: size of cmdptr
 * @stream: stream to read from
 * Return: total bytes read
 */
ssize_t _getline(char **cmdptr, size_t *cmdptr_size, FILE *stream)
{
	static ssize_t command;
	ssize_t total_read;
	char ch = 'x', *buf;
	int readBytes;

	if (command == 0)
		fflush(stream);
	else
		return (-1);
	command = 0;

	buf = malloc(sizeof(char) * 120);
	if (!buf)
		return (-1);
	while (ch != '\n')
	{
		readBytes = read(STDIN_FILENO, &ch, 1);
		if (readBytes == -1 || (readBytes == 0 && command == 0))
		{
			free(buf);
			return(-1);
		}
		if (readBytes == 0 && command != 0)
		{
			command++;
			break;
		}
		if (command >= 120)
			buf = _realloc(buf, command, command + 1);
		buf[command] = ch;
		command++;
	}
	buf[command] = '\0';
	reassign_cmdptr(cmdptr, cmdptr_size, buf, command);
	total_read = command;
	if (readBytes != 0)
		command = 0;
	return (total_read);
}
