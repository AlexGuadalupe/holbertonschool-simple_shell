
#ifndef SHELL_H
#define SHELL_H

#define MAX_INPUT_LENGTH 1024
#define MAX_PATH_LENGHT 1024
#define MAX_PATH_DIRS 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>


#define BUFSIZE 64 /* constant buffer to use in tokenizer functions*/
#define DELIM_I " \t\n" /* delimiters to check in hsh_tokenizer */
#define DELIM_P ":" /* delimiter to check in tokenizer_path */

/**
 * struct choose_builtin - Builtin commands struct
 * @name_builtin: Name of builtin command
 * @func_builtin: Pointer to builtin command functions
 */
typedef struct choose_builtin
{
	char *name_builtin;
	int (*func_builtin)(char **, char *, int *);

} choose_builtins_t;

/* main loop */
/**
 * main - Main loop, recieve input from CLI parse and execute it
 * @argc: Number of arguments passed to the program
 * @argv: Array of arguments
 * Return: Always 0 on success
 */
int main();

/* external variable to access the environment list */
extern char **environ;

/* helper function declarations */
void sigintH(int signum);
char *str_concat(char *s1, char *s2);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* tokenizers function declarations */
char **hsh_tokenizer(char *input);
char **tokenizer_path(char *input);

/* validators function declarations */
char *validate_input(char **arguments, char **argv);
int validate_spaces(char *input);

/* executors */
int hsh_execute(char **arguments, char **argv, int *exit_status);
int hsh_execute_builtins(char **args, char *input_stdin,
			 char **argv, int *exit_status);

/* builtin functions */
int hsh_cd(char **args, char *input_stdin, int *exit_status);
int hsh_setenv(char **args,  char *input_stdin, int *exit_status);
int hsh_unsetenv(char **args,  char *input_stdin, int *exit_status);
int hsh_env(char **args, char *input_stdin, int *exit_status);
int hsh_exit(char **args, char *input_stdin, int *exit_status);
int main_loop(int argc __attribute__((unused)), char **argv __attribute__((unused)));


#endif /* SIMPLE_SHELL_H */
