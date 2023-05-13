#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>

typedef struct node
{
	char *dir;
	struct node *next;
} Node;

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
void handle_env(char **tokens);
void handle_exit(char **tokens);
void exit_handler(char **arg);
char *_getenv(char *name);
Node *path_LL();


int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);

#endif
