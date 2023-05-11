#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>

#define TOKEN_BUFSIZE 1024
#define BUF_SIZE 1024
#define TOKEN_SEPARATOR " \t\r\n\a,;:"

extern char **environ;
/**
 * its a global variable
 */

void print_prompt(void);
char *read_line(void);
char **parse_line(char *command);
char *find_executable(char **tokens);
void child_process(char *command_path, char **tokens);

int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strstr(char *haystack, char *needle);

#endif
