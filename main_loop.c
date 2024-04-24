#include "shell.h"

int main() {
	char input[BUFSIZE]; /* BUFSIZE defined in shell.h*/
	ssize_t n;
	int status;

	while (1) {
		/* Display colored prompt*/
		printf("\033[0;32m"); /* Green color*/
		printf("#(ಠ_ಠ)->$ ");
		printf("\033[0m"); /* Reset color*/

		/* Read command from user*/
		n = read(STDIN_FILENO, input, BUFSIZE);

		/* Check for end of file (Ctrl+D)*/
		if (n == 0)
			break;

		/* Remove trailing newline*/
		if (input[n - 1] == '\n')
			input[n - 1] = '\0';
		/* Tokenize the input*/
		char *token;
		char *args[ARG_MAX]; /* ARG_MAX defined in limits.h*/
		int i = 0;

		token = strtok(input, " ");
		while (token != NULL) {
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL; /* Mark the end of arguments with NULL*/

		/* Execute command using execve*/
		pid_t pid = fork();
		if (pid == -1) {
			/* Error handling for fork failure*/
			perror("fork failed");
			exit(EXIT_FAILURE);
		} else if (pid == 0) {
			/* Child process*/
			if (execve(input, NULL, environ) == -1) {
				/* Error handling for execve failure*/
				if (errno == EACCES) {
					/* Permission denied*/
					printf("\033[0;31m"); /* Red color*/
					printf("Permission denied: %s\n", input);
					printf("\033[0m"); /* Reset color*/
				} else {
					/* Command not found*/
					printf("\033[0;31m"); /* Red color*/
					printf("Command not found: %s\n", input);
					printf("\033[0m"); /* Reset color*/
				}
				exit(EXIT_FAILURE);
			}
		} else {
			/* Parent process*/
			waitpid(pid, &status, 0);
		}
	}

	return 0;
}

