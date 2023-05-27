#include "main.h"

/**
 * get_separators - gets what separated the commands
 * @command: string to find separator in
 * Return: the separators
 */
char **get_separators(char *command)
{
	int len, h, v, z;
	char **separators;
	char sep[4] = " ";

	v = 0;
	h = 0;
	len = _strlen(command);
	separators = (char **)malloc(len * sizeof(char *));
	if (separators == NULL)
		return (NULL);
	for (z = 0; z < len; z++)
	{
		if (command[z] == ';' || command[z] == '|' ||
				command[z] == '&')
		{
			if (v > 0)
			{
				sep[v] = '\0';
				separators[h] = (char *)malloc((v + 1) *
						sizeof(char));
				if (separators[h] == NULL)
					return (NULL);
				_strcpy(separators[h], sep);
				h++;
				v = 0;
			}
			sep[v] = command[z];
			v++;
			if (z + 1 < len && command[z + 1] == command[z])
			{
				sep[v] = command[z + 1];
				v++;
				z++;
			}
		}
	}
	if (v > 0)
	{
		sep[v] = '\0';
		separators[h] = (char *)malloc((v + 1) * sizeof(char));
		if (separators[h] == NULL)
		{
			return (NULL);
		}
		_strcpy(separators[h], sep);
		h++;
	}
	separators[h] = NULL;
	return (separators);
}
