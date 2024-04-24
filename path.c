#include "shell.h"

#define MAX_PATH_LENGHT 1024
#define MAX_PATH_DIRS 100

/**
 * get_path - get the PATH environment variable
 * If the PATH environment variable is not found, an error message is
 * printed and NULL is returned
 * Return: new allocated string containing the PATH if found, NULL if not
 */

char *get_path(void)
{
	char *path = getenv("PATH");

	if (path == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not found\n");
		return (NULL);
	}
	return (strdup(path));
}

/**
 * parse_path - Splits the PATH into individual directories.
 * @path: The PATH environment variable as a string.
 * @num_dirs: A pointer to an integer where the number of
 * directories will be stored.
 * Return: An array of strings containing the directories in the PATH.
 */

char **parse_path(char *path, int *num_dirs)
{

	char **dirs = malloc(MAX_PATH_DIRS * sizeof(char *));
	char *token;
	int count = 0;

	if (dirs == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		return (NULL);
	}
	token = strtok(path, ":");

	while (token != NULL && count < MAX_PATH_DIRS)
	{
		dirs[count++] = strdup(token);
		token = strtok(NULL, ":");
	}

	*num_dirs = count;
	return (dirs);
}

/**
 * search_path - Searches for an executable file in the system path.
 * @command: The executable to find.
 * @path_dirs: The directories to search in.
 * @num_dirs: The number of directories.
 * Return: The full path of the file if it's found, NULL otherwise.
 */

char *search_path(char *command, char *path_dirs[], int num_dirs)
{
	int i;

	for (i = 0; i < num_dirs; i++)
	{
		char path[MAX_PATH_LENGTH];

		snprintf(path, sizeof(path), "%s/%s", path_dirs[i], command);
		if (access(path, X_OK) == 0)
		{
			return (strdup(path));
		}
	}
	return (NULL);
}

/**
 * path_function - Processes the system path.
 * This function gets the PATH environment variable, parses it into individual
 * Return: 0 on success, 1 on error.
 */

int path_function(void)
{
	int num_dirs, i;
	char *path_str = get_path();
	char **path_dirs = parse_path(path_str, &num_dirs);

	if (path_str == NULL)
	{
		return (1);
	}


	if (path_dirs == NULL)
	{
		free(path_str);
		return (1);
	}

	full_path = search_path("bin", path_dirs, num_dirs);
	if (full_path != NULL)
	{
		printf("Full path of 'bin': %s\n", full_path);
		free(full_path);
	}
	else
	{
		printf("'bin' not found in ther specified directories.\n");
	}
	
	for (i = 0; i < num_dirs; i++)
	{
		free(path_dirs[i]);
	}
	free(path_dirs);

	return (0);
}
