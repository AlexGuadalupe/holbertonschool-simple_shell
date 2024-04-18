#include "shell.h"

#define MAX_PATH_LENGHT 1024
#define MAX_PATH_DIRS 100

/**
 * get_path - get the PATH environment variable
 * parse_path - parse the PATH environment variable
 * search_path - search the PATH environment variable
 * Return: NULL
 */
char* get_path()
{
	char* path = getenv("PATH");
	if (path == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not found\n");
		return(NULL);
	}
	return(strdup(path));
}

char** parse_path(char* path, int* num_dirs)
{

	char** dirs = malloc(MAX_PATH_DIRS * sizeof(char*));
	if (path_dirs == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		return(NULL);
	}
	char* token = strtok(path, ":");
	int count = 0;

	while (token != NULL && count < MAX_PATH_DIRS)
	{
		dirs[count++] = strdup(token);
		token = strtok(NULL, ":");
	}

	*num_dirs = count;
	return(path_dirs);
}


char* search_path(char* command, char* path_dirs[], int num_dirs)
{
	int i;
	for(i = 0; i < num_dirs; i++)
	{
		char path[MAX_PATH_LENGHT];
		snprintf(path, sizeof(path), "%s/%s", path_dirs[i], command);
		if (access(path, X_OK) == 0)
		{
			return strdup(path);
		}
	}
	return(NULL);
}

int main()
{
	char* path_str = get_path();
	if (path_str == NULL)
	{
		return (1);
	}

	int num_dirs;
	char** path_dirs = parse_path(path_str, &num_dirs);
	if (path_dirs == NULL)
	{
		free(path_str);
		return 1;
	}


	for (int i = 0; i < num_dirs; i++)
	{
		printf("Directory %d: %s\n", i + 1, path_dirs[i]);
	}

	for (int i = 0; i < num_dirs; i++)
	{
		free(path_dirs[i]);
	}
	free(path_dirs);

	return (0);
}
