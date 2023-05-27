#include "main.h"

/**
 * checks_builtin - checks to see if it is a builtin
 * @tokens: tokenized command
 * @buffer: stores command pointer
 * Return: 1 on sucess
 */
int checks_builtin(char **tokens, char *buffer)
{
	if (builtin_handler(tokens, buffer))
		return (1);
	else if (**tokens == '/')
	{
		execute(tokens[0], tokens);
		return (1);
	}
	return (0);
}

/**
 * execute - executes commands
 * @command: command inputted by user
 * @cmdptr: array of pointers to commands
 */
void execute(char *command, char **cmdptr)
{
	pid_t pid;
	int status;
	char **envt = environ;

	pid = fork();
	if (pid < 0)
		perror("fork failure");
	if (pid == 0)
	{
		execve(command, cmdptr, envt);
		perror("execve failure");
		free(command);
		frees_buf(cmdptr);
		exit(98);
	}
	else
	{
		wait(&status);
	}
}

/**
 * frees_buf - frees allocated buffer
 * @buffer: buffer to be freed
 */
void frees_buf(char **buffer)
{
	int index = 0;

	if (!buffer || buffer == NULL)
		return;
	while (buffer[index])
	{
		free(buffer[index]);
		index++;
	}
	free(buffer);
}

/**
 * builtin_handler - handles execution of builtin command
 * @tokens: tokenized input
 * @inputstr: command read from input stream
 * Return: 1 on execution, 0 otherwise
 */
int builtin_handler(char **tokens, char *inputstr)
{
	if (_strcmp(*tokens, "env") == 0)
	{
		handle_env();
		return (1);
	}
	else if (_strcmp(*tokens, "exit") == 0)
	{
		exit_handler(tokens, inputstr);
		return (1);
	}
	return (0);
}

/**
 * exit_handler - handles exit command
 * @tokens: tokenized input string
 * @inputstr: input read from stream(stdin)
 */
void exit_handler(char **tokens, char *inputstr)
{
	free(inputstr);
	frees_buf(tokens);
	exit(0);
}
