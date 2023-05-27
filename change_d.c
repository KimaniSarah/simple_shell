#include "main.h"
/**
 * change_d - changes dir
 * @tokens: the tokens
 */
void change_d(char *tokens)
{
	char *home_dir, *old_dir, current_path[MAX_PATH_LENGTH];

	if (tokens == NULL)
	{
		home_dir = _getenv("HOME");
		if (home_dir == NULL)
		{
			perror("error");
			return;
		}
		if (chdir(home_dir) != 0)
		{
			perror("chdir() error");
			return;
		}
	}
	else if (_strcmp(tokens, "-") == 0)
	{
		old_dir = _getenv("OLDPWD");
		if (old_dir == NULL)
		{
			perror("error");
			return;
		}
		if (chdir(old_dir) != 0)
		{
			perror("chdir() error");
		}
	}
	else
	{
		if (chdir(tokens) != 0)
		{
			perror("error");
		}
	}
	if (getcwd(current_path, sizeof(current_path)) == NULL)
	{
		perror("getcwd() error");
	}
}
