#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 256
#define PROMPT "simple_shell: "

/**
 * main - Entry point of the program
 *
 * Description: This function reads commands from the user and executes them.
 *
 * Return: 0 on success, or an error code on failure
 */

int main(void)
{
char cmd[MAX_CMD_LEN];
char *argv[2];
char *envp[] = { NULL };

while (1)
{
printf(PROMPT);
if (fgets(cmd, MAX_CMD_LEN, stdin) == NULL)
{
printf("\n");
exit(0);
}
cmd[strcspn(cmd, "\n")] = 0;

if (strlen(cmd) == 0)
{
continue;
}
argv[0] = cmd;
argv[1] = NULL;

if (execve(cmd, argv, envp) == -1)
{
perror(cmd);
}
}
return (0);
}
