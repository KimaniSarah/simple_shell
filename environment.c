#include "main.h"

/**
 * insert_node_at_end - add node to the end of a list
 *
 * @head:
 * @str:
 * Return:
 */
envlist *insert_node_at_end(envlist **head, const char *str)
{
	envlist *newNode, *tailNode;

	newNode = malloc(sizeof(envlist));
	if (newNode == NULL)
		return (NULL);

	newNode->str = _strdup(str);

	if (newNode->str = NULL)
	{
		free(newNode);
		return (NULL);
	}

	newNode->next = NULL;

	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		tailNode = *head;
		while (tailNode->next != NULL)
		{
			tailNode = tailNode->next;
		}
		tailNode->next = newNode;
	}

	return (newNode);
}

/**
 * _setenv - initializes a new envt var, or modifies an existing one
 *
 * @name: name of the environment variable
 * @value:
 * @overwrite:
 * Return: 0 on Success, -1 on failure
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	overwrite = 1;
	char *Envar;
	char *setenvError = "Invalid name or value.\n";

	if (!name || !*name || _strchr(name, '=') || !value)
	{
		write(STDERR_FILENO, setenvError, _strlen(setenvError));
		return (-1);
	}
	Envar = _getenv(name);
	if (Envar)
		overwrite = 1;
	else
	{
		Envar = malloc(sizeof(char) * (_strlen(name) + 2));
		if (Envar == NULL)
			return (-1);

		_strcpy(Envar, name);
	}
	Envar = _realloc(Envar, sizeof(char) * (_strlen(value) + _strlen(name) + 2));
	if (!Envar)
		return (-1);

	if (overwrite)
		_strcpy(Envar + _strlen(Envar), value);
	else
	{
		_strcpy(Envar + _strlen(Envar), '=');
		_strcpy(Envar + _strlen(Envar), value);
		insert_node_at_end(&environ, Envar);
	}

	return (0);
}

/**
 * _unsetenv - removes an environment variable
 *
 * @name:
 * Return: 0 on Success, -1 on failure
 */
int unsetenv(const char *name)
{
	char **envariable, **position;
	size_t length;
	char *unsetenvError = "Invalid name.\n"

	if (name == NULL || *name == NULL || _strchr(name, '='))
	{
		write(STDERR_FILENO, unsetenvError, _strlen(unsetenvError));
		return (-1);
	}

	envariable = environ;
	while (*envariable)
	{
		if (_strncmp(name, *envariable, length = _strlen(name)) == 0 &&
				(*envariable)[length] == '=')
		{
			position = envariable;
			do
				position[0] = position[1];
			while (*position++);
		}
		else
		{
			envariable++;
		}
	}
	return (0);
}

