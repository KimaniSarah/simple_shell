#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <time.h>

/**
 * struct node - linked list
 * @dir: pointer to dir
 * @next: next node
 */
typedef struct node
{
	char *dir;
	struct node *next;
} Node;

/**
 * struct - struct for tokenization
 * @last_token: last token
 */
typedef struct
{
	char *last_token;
} tokenise;

/**
 * struct shell -tests for interactive shell
 * @modeInteractive: mode
 */
struct shell
{
	bool modeInteractive;
} shell;
#define MAX_PATH_LENGTH 1024
#define TOKEN_BUFSIZE 1024
#define BUF_SIZE 1024
#define TOKEN_SEPARATOR " \t\r\n\a,;:"

/*global variables*/
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

/*command helper functions*/
/*void print_prompt(void);*/
char *read_line(void);
int set_check(char **token);
void change_directory(const char *path);
void change_d(char *tokens);
char **parse_line(char *command);
char *find_executable(char **tokens);
/*int child_process(char *command_path, char **tokens);*/
/*void handle_env(char **tokens);*/
/*void handle_exit(char **tokens);*/
/*void exit_handler(char **arg);*/
char *_getenv(char *name);
Node *path_LL();

char *add_path(char *command_path, char *inputstr);
char *path_validate(char **path, char *inputstr);
char *get_path(void);
void prompt(void);
void sign_handler(__attribute__((unused))int num);
int checks_builtin(char **tokens, char *buffer);
void execute(char *command, char **cmdptr);
void frees_buf(char **buffer);
void handle_env(void);
int builtin_handler(char **tokens, char *inputstr);
void exit_handler(char **tokens, char *inputstr);
void exit_argument(char **arg);
char **handle_separators(char *command, int *numCommands);
/*char **handle_separators(char *command);*/
/*int change_directory(char **args);*/
ssize_t _getline(char **command, size_t *n, FILE *stream);
int _setenv(char *envname, char *val, int overwrite);
int _unsetenv(char *envname);
void handle_comment(char *buffer);
/*char **get_separators(char *command);*/

/*void operand(char *command);*/
/*void operand(char *command);*/
char *_strtok(tokenise *str, char *string, const char *delimiter);
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

