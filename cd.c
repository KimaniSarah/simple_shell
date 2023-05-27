#include "main.h"
/**
 * change_directory - changes directories
 * @path:the path
 * Return: void
 */
void change_directory(const char *path)
{
	char current_path[MAX_PATH_LENGTH];

	if (getcwd(current_path, sizeof(current_path)) == NULL)
	{
		perror("getcwd() error");
		return;
	}
	if (chdir(path) != 0)
	{
		perror("chdir() error");
		return;
	}
	if (setenv("PWD", path, 1) != 0)
	{
		perror("setenv() error");
		return;
	}
	if (getcwd(current_path, sizeof(current_path)) == NULL)
	{
		perror("getcwd() error");
		return;
	}
}
