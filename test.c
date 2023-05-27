#include "main.h"

/**
 * set_check - handle setenv and unsetenv
 * @token: array of tokens
 * Return: 1 if the command is setenv or unsetenv, 0 otherwise
 */
int set_check(char **token)
{
    if (token == NULL || *token == NULL)
        return 0;

    if (_strcmp(token[0], "setenv") == 0)
    {
        if (token[1] == NULL || token[2] == NULL || token[3] != NULL)
        {
            perror("Invalid setenv command");
            return 1;
        }

        if (setenv(token[1], token[2], 1) != 0)
        {
            perror("Failed to set environment variable");
            return 1;
        }

        return 1;
    }

    if (_strcmp(token[0], "unsetenv") == 0)
    {
        if (token[1] == NULL)
        {
            perror("Invalid unsetenv command");
            return 1;
        }

        if (unsetenv(token[1]) != 0)
        {
            perror("Failed to unset environment variable");
            return 1;
        }

        return 1;
    }

    return 0;
}

