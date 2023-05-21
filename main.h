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
typedef struct
{
	char* last_token;
} tokenise;
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
int child_process(char *command_path, char **tokens);
void handle_env(char **tokens);
void handle_exit(char **tokens);
void exit_handler(char **arg);
char *_getenv(char *name);
Node *path_LL();
char **handle_separators(char *command);
int change_directory(char **args);
ssize_t _getline(char **command, size_t *n, FILE *stream);
int _setenv(char *name, char *value, int overwrite);
int _unsetenv(char *name);
char **get_separators(char *command);

/*char *_strtok(char *cmdInput, char *delimiter);*/
void operand(char *command);
void procfilecmd(char *file, int shell_intereactive);
void operand(char *command);
char* _strtok(tokenise *str, char* string, const char* delimiter);
char *my_strchr(const char *str, int c);
void tokenise_str(tokenise *str);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
char *_strdup(char *str);
int _atoi(char *str);
char *_memcpy(char *dest, char *src, size_t size);
/*void *_realloc(void *oldPtr, int size);*/
void *_realloc(void *oldPtr, int oldSize, int size);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
void free_tokens(char **tokens);
int _strncmp(char *s1, char *s2, int n);

#endif

