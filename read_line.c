#include "main.h"
/**
 * print_prompt - prints and display the prompt to indicate the user can
 * input the command and its argumsnts
 * Return:void
 */
void print_prompt(void)
{
	printf("simple_shell_project$");
	fflush(stdout);
}
/**
 * read_line - reads the input put into the prompt by the user
 * Return:void
 */
char *read_line(void)
{
	char *command;
	size_t n;
	size_t read;
	int index;

	command = NULL;
	n = 0;

	read = getline(&command, &n, stdin);
	if (read == -1)
	{
		perror("getline failed");
		exit(1);
	}
	index = read - 1;
	if (command[index] == '\n')
	{
		command[index] = '\0';
	}
	free(command);
	return (0);
}
