#include "main.h"

/**
 * change_directory - chnages current working directory
 *
 * @args: an array of arguments passed
 * Return: 0 on success, 1 on failure
 */
int change_directory(char **args)
{
	char *directory = args[1], *currentPwd;
	char *homedir = getenv("HOME"), *oldPwd = getenv("PWD");
	char *cdError = "the user has not changed directories before\n";
	char *dirError = "There is no such file or directory\n";

	if (directory == NULL)
	{

		chdir(homedir);
		setenv("PWD", homedir, 1);
		return (0);
	}
	if (strcmp(directory, "-") == 0)
	{
		if (oldPwd == NULL)
		{
			write(STDERR_FILENO, cdError, strlen(cdError));
			return (1);
		}
		directory = oldPwd;
	}
	if (chdir(directory) != 0)
	{
		write(STDERR_FILENO, dirError, strlen(dirError));
		return (1);
	}
	currentPwd = getcwd(NULL, 0);
	if (currentPwd == NULL)
	{
		perror("Failure getting the cwd");
		return (1);
	}

	setenv("OLDPWD", oldPwd, 1);
	setenv("PWD", currentPwd, 1);
	free(currentPwd);

	return (0);
}
