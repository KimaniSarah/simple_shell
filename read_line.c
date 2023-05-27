#include "main.h"
/**
 * print_prompt - prints and display the prompt to indicate the user can
 * input the command and its argumsnts
 * Return:void
 */
void print_prompt(void)
{
	char *prompt = "$ ";

	write(1, prompt, _strlen(prompt));
}
/**
 * read_line - reads the input put into the prompt by the user
 * Return:void
 */
char *read_line(void)
{
	char *command;
	size_t n;
	ssize_t read;
	int index;

	command = NULL;
	/**
	 * initialised to null to allow getline to allocate space required
	 */
	n = 0;

	read = getline(&command, &n, stdin);
	if (read == -1)
	{
		perror("getline failed");
		exit(1);
	}

	index = read - 1;
	/**
	 * read is the no of bytes written to command so we minus 1
	 * because indexes start from 0
	 */
	if (command[index] == '\n')
	{
		command[index] = '\0';
	}
	/**
	 * replace '\n' with '\0' to make it a proper string
	 */
	return (command);
}
