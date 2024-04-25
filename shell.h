#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;
#define MAX_INPUT_SIZE 1024
#define MAX_CMD_SIZE 1024
#define DELIM " \t\r\n\a"
#define PROMPT "simple_shell "

void print_env(void);
int read_command(char *input, size_t __attribute__((unused)) file_stream, char *name);
char *search_path(char*command);
void print_not_found(char *cmd, char *name);
int read_command(char *cmd_arr[], char *name);
int _str_cmp(char *string1, const char *string2, int num_chars);
char *_getenv(const char *env_var);
int execute_command(char *cmd_arr[], char *name);

#endif /* SHELL_H */
