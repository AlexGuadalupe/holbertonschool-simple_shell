#include "shell.h"

char *search_path(char *command) { 
{
	char *path;
	char *new_path;
	int i;
	int j;
	char *path_tokens;
	char *path_array[100];
	char *s2;
	struct stat buf;

	path = strdup(_getenv("PATH"));
	if (path == NULL)
	{
		return NULL;
	}

	new_path = malloc(sizeof(char) * 1000);
	if (new_path == NULL)
	{
		free(path);
		return NULL;
	}

	i = 0;
	j = 0;
	s2 = command;

	if (_getenv("PATH")[0] == ':')
	{
		if (stat(command, &buf) == 0)
		{
			free(path);
			return strdup(command);
		}
	}

	path_tokens = strtok(path, ":");
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
			return new_path;
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
		return strdup(command);
	}
	return NULL;
}

