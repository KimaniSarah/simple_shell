#include "main.h"

/**
 * sign_handler - keeps track of the mode
 * @num: signal no
 */
void sign_handler(__attribute__((unused))int num)
{
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}

/**
 * prompt - prints $ to prmompt user in interactive mode
 */
void prompt(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO == 1)))
		shell.modeInteractive = 1;
	if (shell.modeInteractive)
		write(STDERR_FILENO, "$ ", 2);
}

/**
 * handle_comment - handles #
 * @buffer: stores input string
 */
void handle_comment(char *buffer)
{
	int index;

	while (buffer[index] != '\0')
	{
		if (buffer[index] == '#')
		{
			buffer[index] = '\0';
		}
		index++;
	}
}
