#include "main.h"

int main(void)
{
    char *command = NULL;
    size_t n = 0;
    ssize_t bytesRead;

    while (1)
    {
        printf("Enter a line of text (or 'quit' to exit):\n");

        bytesRead = getline(&command, &n, stdin);

        if (bytesRead == -1)
        {
            printf("Error reading input.\n");
            break;
        }

        if (strcmp(command, "quit") == 0)
        {
            printf("Exiting...\n");
            break;
        }

        printf("Input line: %s\n", command);
    }

    free(command);
    return 0;
}

