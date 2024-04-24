#include "shell.h"

int execute_command(char **args) {
	char *path = _getenv("PATH");
	if (!path) {
		fprintf(stderr, "Error: PATH variable not found.\n");
		return 1;
	}

	char *token;
	char *full_path = malloc(strlen(path) + strlen(args[0]) + 2);
	if (!full_path) {
		perror("malloc");
		return 1;
	}
	strcpy(full_path, path);

	token = strtok(full_path, ":");
	while (token) {
		char *cmd_path = malloc(strlen(token) + strlen(args[0]) + 2);
		if (!cmd_path) {
			perror("malloc");
			free(full_path);
			return 1;
		}
		sprintf(cmd_path, "%s/%s", token, args[0]);
		if (access(cmd_path, X_OK) == 0) {
			pid_t pid = fork();
			if (pid == -1) {
				perror("fork");
				free(cmd_path);
				free(full_path);
				return 1;
			} else if (pid == 0) {
				execve(cmd_path, args, NULL);
				perror("execve");
				exit(EXIT_FAILURE);
			} else {
				wait(NULL);
				free(cmd_path);
				free(full_path);
				return 0;
			}
		}
		free(cmd_path);
		token = strtok(NULL, ":");
	}

	fprintf(stderr, "Error: command '%s' not found\n", args[0]);
	free(full_path);
	return 1;
}

