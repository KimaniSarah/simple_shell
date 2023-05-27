#include "main.h"

/**
 * _pid - retrieves current pid
 *
 * Return: current pid
 */
char *_pid(void)
{
	ssize_t index = 0, execfile;
	char *buf;

	execfile = open("/proc/self/stat", O_RDONLY);
	if (execfile == -1)
	{
		perror("Cannot read from file");
		return (NULL);
	}
	buf = malloc(120);
	if (!buf)
	{
		close(execfile);
		return (NULL);
	}

	read(execfile, buf, 120);
	while (buf[index] != ' ')
	{
		index++;
	}
	buf[index] = '\0';
	close(execfile);
	return (buf);
}

/**
 * get_val - gets val of env var
 * @var: env var
 * @length: length of env var
 * Return: value of env var
 */
char *get_val(char *var, int length)
{
	char **variable_address;
	char *rep = NULL, *h, *env_var;

	env_var = malloc(length + 1);
	if (!env_var)
		return (NULL);
	env_var[0] = '\0';

	_strncat(env_var, var, length);

	variable_address = _getenv(env_var);
	free(env_var);
	if (variable_address)
	{
		h = *variable_address;
		while (*h != '=')
		{
			h++;
		}
		h++;
		rep = malloc(_strlen(h) + 1);
		if (rep)
			_strcpy(rep, h);
	}
	return (rep);
}

/**
 * var_rep - var replacement
 * @inputline: pointer to args and cmds
 * @ret_val: return val of last cmd
 */
void var_rep(char **inputline, int *ret_val)
{
	int x, y = 0, length;
	char *rep = NULL, *old = NULL, *new;

	old = *inputline;
	for (x = 0; old[x]; x++)
	{
		if (old[x] == '$' && old[x + 1] && old[x + 1] != ' ')
		{
			if (old[x + 1] == '$')
			{
				rep = _pid();
				y = x + 2;
			}
			else if (old[x + 1] == '?')
			{
				rep = _atoi(*ret_val);
				y = x + 2;
			}
			else if (old[x + 1])
			{
				for (y = x + 1; old[y] && old[y] != '$' &&
						old[y] != ' '; y++)
					;
				length = y - (x + 1);
				rep = get_val(&old[x + 1], length);
			}
			new = malloc(x + _strlen(rep) + _strlen(&old[y]) + 1);
			if (!inputline)
				return;
			new[0] = '\0';
			_strncat(new, old, x);
			if (rep)
			{
				_strcat(new, rep);
				free(rep);
				rep = NULL;
			}
			_strcat(new, &old[y]);
			free(old);
			*inputline = new;
			old = new;
			x = -1;
		}
	}
}
