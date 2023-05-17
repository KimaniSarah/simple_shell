#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main(void) {
    char *command;

    while (1) {
        print_prompt();
        command = read_line();

        if (strcmp(command, "exit") == 0) {
            break;
        }

        printf("Command entered: %s\n", command);

        free(command);
    }

    return 0;
}

