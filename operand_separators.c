#include"main.h"
void operand(char *command)
{
	char *command_now;
	char *token;
	char *delimiter;
	char **tokens;
	char *command_path;
	int status;

	delimiter = "&&";
	command_now = _strdup(command);
	if (command_now == NULL)
	{
		return;
	}

	token = _strtok(command_now, delimiter);
	while (token != NULL)
	{
		tokens = parse_line(token);
		command_path = find_executable(tokens);
		status = child_process(command_path, tokens);
		if (_strcmp(delimiter, "&&") == 0 && status != 0)
		{
			break;
		}
		else if (_strcmp(delimiter, "||") == 0 && status == 0)
		{
			break;
		}
		token = _strtok(NULL, delimiter);
		delimiter = (delimiter[0] == '&' && delimiter[1] == '&') ? "||" : "&&";
		/**
		 * If the current delimiter is &&, it changes it to || for the next iteration, and vice versa.
		 */
	}
}
