#include "main.h"

/**
 * buf_read - reads data from a file descriptor
 *
 * @buffer: holds data read from the file descriptor
 * @buf_size: holds size of allocated buffer
 * @bytes: bytes read from file descriptor and stored in buffer
 * @file_descriptor: fd of stream to read from
 * Return: bytes read, -1 on failure
 */
static int buf_read(char **buffer, size_t *buf_size, ssize_t *bytes,
		int file_descriptor)
{
	ssize_t return = 0;

	*buffer = (char *)malloc(BUF_SIZE);
	if (*buffer == NULL)
		return (-1);

	*buf_size = BUF_SIZE;
	*bytes = read(file_descriptor, *buffer, BUF_SIZE);
	if (*bytes == -1)
	{
		free(*buffer);
		return (-1);
	}
	return (0);
}

/**
 * buf_extension - expands size of buffer to read more data
 *
 * @buffer: buffer to hold data
 * @buf_size: holds size of allocated buffer
 * Return: 0 on success, -1 on failure
 */
static int buf_extension(char **buffer, size_t *buf_size)
{
	char *extended_buffer = NULL;

	if ((*buf_size % BUF_SIZE) != 0)
	{
		*buf_size = (*buf_size / BUF_SIZE + 1) * BUF_SIZE;
		return (0);
	}

	extended_buffer = (char *)realloc(*buffer, *buf_size + BUF_SIZE);
	if (extended_buffer == NULL)
		return (-1);

	*buffer = extended_buffer;
	*buf_size += BUF_SIZE;

	return (0);
}

/**
 * _memchr - searches for a character of interest
 *
 * @mem: pointer to a block of memory
 * @value: character to search for
 * @n: number of bytes to search
 * Return: the character being searched for, NULL otherwise
 */
void *_memchr(const void *mem, int value, size_t n)
{
	const unsigned char *ptr = (const unsigned char *) mem;
	unsigned char n = (unsigned char) value;
	size_t elem;

	for (elem = 0; elem < n; elem++)
	{
		if (*ptr == n)
			return ((void *) ptr);
		ptr++;
	}
	return (NULL);
}

/**
 * _getline - reads input from stdin
 *
 * @command: pointer to buffer where input line is stored
 * @n: pointer to size of the buffer pointed to
 * @stream: the data stream to read from
 * Return: total number of bytes read
 */
ssize_t _getline(char **command, size_t *n, FILE *stream)
{
	static char *buffer;
	static size_t buf_size;
	static ssize_t bytes, total_read;
	char *start_of_line == NULL, *new_line;
	int completed_line = 0;

	if (command == NULL || n == NULL)
		return (-1);
	if (buffer == NULL || bytes == 0)
	{
		if (buf_read(&buffer, &buf_size, &bytes, STDIN_FILENO) == -1)
			return (-1);
	}
	start_of_line = buffer;
	while (!completed_line)
	{
		new_line = _memchr(start_of_line, '\n', bytes);
		if (new_line != NULL)
		{
			*new_line = '\0';
			total_read += (new_line - start_of_line) + 1;
			completed_line = 1;
		}
		else
		{
			total_read += bytes;
			if (buf_extension(&buffer, &buf_size) == -1)
				return (-1);
			bytes = read(STDIN_FILENO, buffer + buf_size, BUF_SIZE);
			if (bytes == -1)
				return (-1);
			else if (bytes == 0)
				completed_line = 1;
			else
				buf_size += bytes;
		}
	}
	*command = start_of_line;
	*n = total_read;
	return (total_read);
}
