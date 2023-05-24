#include "main.h"

/**
 * processfile - opens a file, reads and processes it line by line
 * @file: file to be opened
 */
void processfile(const char *file)
{
	FILE *execfile;
	char *cmdline;
	size_t length;
	ssize_t read;

	execfile = fopen(file, "r");
	if (execfile == NULL)
	{
		perror("cannot open file");
		return;
	}

	cmdline = NULL;
	length = 0;

	while ((read = _getline(&cmdline, &length, execfile)) != -1)
	{
		/*processline*/
		cmdline[read - 1] = '\0';
		/*process commands*/
	}
	free(cmdline);
	fclose(execfile);
}

/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: pointer to array of arguments
 * Return: 0 (Success)
 */
int main(int argc, char **argv)
{
	int index, status, ind;
	char *command, *command_path, **separator;
	size_t bufsize;
	char **commands;
	int shell_interactive;

       	shell_interactive = isatty(STDIN_FILENO) ? 1 : 0;

	if (argc > 1)
	{
		for (ind = 1; ind < argc; ind++)
		{
			processfile(argv[ind]);
		}
	}
	else
	{
		bufsize = BUF_SIZE;
		command_path = NULL;
		command = (char *)malloc(bufsize * sizeof(char));
		if (command == NULL)
		{
			perror("malloc failed");
			exit(1);
		}
		while(1)
		{
			if (shell_interactive)
			{
				print_prompt();
				fflush(stdout);
				command = read_line();
				if (feof(stdin))
				{
					write(STDOUT_FILENO, "\n", 1);
					break;
				}
				separator = get_separators(command);
				commands = handle_separators(command);
				for (index = 0; commands[index] != NULL; index++)
				{
					argv = parse_line(commands[index]);
					if (_strcmp(argv[0], "exit") == 0)
					{
						if (argv[1] != NULL)
						{
							exit_handler(argv);
						}
						else
						{
							handle_exit(argv);
						}
					}
					else if (_strcmp(argv[0], "env") == 0)
					{
						handle_env(argv);
					}
					else if (_strcmp(argv[0], "cd") == 0)
					{
						change_directory(argv);
					}
					else
					{
						command_path = find_executable(argv);
						status = 0;
						status = child_process(command_path, argv);
						if (separator != NULL && separator[index] != NULL)
						{
							if (_strcmp(separator[index], "&&") == 0 && status != 0)
							{
								break;
							}
							else if (_strcmp(separator[index], "||") == 0 && status == 0)
							{
								break;
							}
						}
					}
					free_tokens(argv);
				}
				free_tokens(commands);
				free_tokens(separator);
			}
		}
	}
	free(command);
	return (0);
}
