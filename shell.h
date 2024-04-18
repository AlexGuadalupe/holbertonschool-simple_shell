#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>
#

#define BUFSIZE 64 /* constant buffer to use in tokenizer functions*/
#define DELIM_I " \t\n" /* delimiters to check in hsh_tokenizer */
#define DELIM_P ":" /* delimiter to check in tokenizer_path */

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

#endif /* SIMPLE_SHELL_H */
