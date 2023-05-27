#include "main.h"
int main(int argc, char *argv[])
{
	size_t cmdline_len;
    char cmdline[BUF_SIZE];
    char **token = NULL, **pathptr = NULL;
    char *command_path = NULL, *findpath = NULL;
    FILE *input_stream;

    signal(SIGINT, sign_handler);

    if (argc > 1) {
        input_stream = fopen(argv[1], "r");
        if (input_stream == NULL) {
            perror("Error opening file");
            return -1;
        }
    } else {
        input_stream = stdin;
    }

    while (1)
    {
        frees_buf(token);
        frees_buf(pathptr);
        free(command_path);
        prompt();
        fflush(stdout);

        if (fgets(cmdline, sizeof(cmdline), input_stream) == NULL)
            break;

        cmdline_len = strlen(cmdline);
        if (cmdline_len > 0 && cmdline[cmdline_len - 1] == '\n')
            cmdline[cmdline_len - 1] = '\0';

        token = parse_line(cmdline);
        if (token == NULL || *token == NULL || **token == '\0')
            continue;

        if (checks_builtin(token, cmdline))
            continue;

        findpath = get_path();
        pathptr = parse_line(findpath);
        command_path = path_validate(pathptr, token[0]);
        if (!command_path)
            perror(argv[0]);
        else
            execute(command_path, token);
    }

    if (input_stream != stdin) {
        fclose(input_stream);
    }

    return 0;
}

