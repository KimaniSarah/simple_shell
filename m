#include "main.h"
int main(void)
{
	char *command;
	char **commands;
	char **tokens;
	
	while (1)
	{
		print_prompt();
        command = read_line();

            tokens = parse_line(commands[i]);
            command_path = find_executable(tokens);

            if (command_path != NULL) {
                if (strcmp(tokens[0], "exit") == 0) {
                    handle_exit(tokens);
                } else if (strcmp(tokens[0], "cd") == 0) {
                    change_directory(tokens);
                } else if (strcmp(tokens[0], "env") == 0) {
                    handle_env(tokens);
                } else {
                    child_process(command_path, tokens);
                }
            }

            free(tokens);
        }

        free(commands);
        free(command);
    }

    return 0;
}

