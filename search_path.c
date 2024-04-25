#include "shell.h"

/**
 * search_path - Finds the full path of a command.
 * @command: The command to find.
 * Return: A pointer to a string containing the full path of the command,
 * or NULL if the command is not found in the PATH.
 */
char *search_path(char *command)
{
	char *path = strdup(_getenv("PATH"));
	int i = 0, j = 0;
	char *path_tokens = strtok(path, ":");
	char *path_array[100];
	char *s2 = command;
	char *new_path = NULL;
	struct stat buf;

	new_path = malloc(sizeof(char) * 1000);
	if (_getenv("PATH")[0] == ':')
	{
		if (stat(command, &buf) == 0)
		{
			return (strdup(command));
		}
	}
	while (path_tokens != NULL)
	{
		path_array[i++] = path_tokens;
		path_tokens = strtok(NULL, ":");
	}
	path_array[i] = NULL;
	for (j = 0; path_array[j]; j++)
	{
		strcpy(new_path, path_array[j]);
		strcat(new_path, "/");
		strcat(new_path, s2);

		if (stat(new_path, &buf) == 0)
		{
			free(path);
			return (new_path);
		}

		else
		{
			new_path[0] = 0;
		}
	}
	free(path);
	free(new_path);

	if (stat(command, &buf) == 0)
	{
		return (strdup(command));
	}
	return (NULL);
}
