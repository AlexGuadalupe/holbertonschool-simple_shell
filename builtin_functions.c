#include "shell.h"

int hsh_cd(char **args, char *input_stdin, int *exit_status)
{
	int stat; 
	char s[128]; 


	getcwd(s, sizeof(s));

	(void)input_stdin;
	(void)exit_status;


	if (args[1] == NULL)

		stat = chdir(getenv("HOME"));

	else if (strcmp(args[1], "-") == 0)

		stat = chdir(getenv("OLDPWD"));

	else if (strcmp(args[1], "~") == 0)

		stat = chdir(getenv("HOME"));
	else 
		stat = chdir(args[1]);


	if (stat == -1)
		perror("cd had an error");

	setenv("OLDPWD", s, 1);
	setenv("PWD", getcwd(s, sizeof(s)), 1);
	return (1);
}


int hsh_setenv(char **args,  char *input_stdin, int *exit_status)
{
	int n_tokens = 0; 

	(void)input_stdin;
	(void)exit_status;


	while (args[n_tokens] != NULL)
	{
		n_tokens++;
	}


	if (n_tokens == 3)
		setenv(args[1], args[2], 1);


	else if (n_tokens != 3)
		fprintf(stderr, "Try use \"setenv [KEY] [VALUE]\"\n");

	return (1);
}


int hsh_unsetenv(char **args,  char *input_stdin, int *exit_status)
{
	int n_tokens = 0; 

	(void)input_stdin;
	(void)exit_status;


	while (args[n_tokens] != NULL)
	{
		n_tokens++;
	}


	if (n_tokens == 2)

		unsetenv(args[1]);

	else if (n_tokens != 2)
		fprintf(stderr, "Try use \"unsetenv [KEY]\"\n");

	return (1);
}

/**
 * hsh_exit - Exit the shell
 * Return: Always returns 0 to indicate successful execution
 */
int hsh_exit(void)
{
	exit(EXIT_SUCCESS);
}

/**
 * hsh_env - Print the current environment
 * Return: Always returns 0 to indicate successful execution
 */
int hsh_env(void)
{
	extern char **environ; /* Access to the environment variables*/
	char **env = environ;  /* Pointer to traverse the environment variables*/

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}

	return 0;
}
