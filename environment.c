#include "main.h"

/**
 * insert_node_at_end - add node to the end of a linked list envlist
 *
 * @head: pointer to first node in list
 * @str: mallo'ced string
 * Return: address of new node, NULL if failed
 */
envlist *insert_node_at_end(envlist **head, const char *str)
{
	envlist *newNode, *tailNode;

	newNode = malloc(sizeof(envlist));
	if (newNode == NULL)
		return (NULL);

	newNode->str = strdup(str);

	if (newNode->str == NULL)
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
int _setenv(char *name, char *value, int overwrite)
{
	char *envar;
	char *setenvError = "Invalid name or value.\n";
	envlist *node, **head;
	size_t length;

	if (!name || !*name || strchr(name, '=') || !value)
	{
		write(STDERR_FILENO, setenvError, _strlen(setenvError));
		return (-1);
	}
	envar = _getenv(name);
	if (envar)
		overwrite = 1;
	else
	{
		envar = malloc(sizeof(char) * (_strlen(name) + 2));
		if (envar == NULL)
			return (-1);

		_strcpy(envar, name);
	}
	envar = _realloc(envar, sizeof(char) * (_strlen(value) + _strlen(name) + 2));
	if (!envar)
		return (-1);

	if (overwrite)
		_strcpy(envar + _strlen(envar), value);
	else
	{
		_strcpy(envar + _strlen(envar), "=");
		_strcpy(envar + _strlen(envar), value);
		insert_node_at_end(&environ, envar);
	}

	return (0);
}

/**
 * _unsetenv - removes an environment variable
 *
 * @name:
 * Return: 0 on Success, -1 on failure
 */
int _unsetenv(char *name)
{
	char **envariable, **position;
	size_t length;
	char *unsetenvError = "Invalid name.\n";

	if (name == NULL || !*name || strchr(name, '='))
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
