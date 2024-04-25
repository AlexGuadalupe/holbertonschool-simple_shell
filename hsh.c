#include "shell.h"
#include <ctype.h>
#define MAX_COMMAND_LENGTH 1024

int main() {
char command[MAX_COMMAND_LENGTH];
pid_t pid;
char *ptr;

while (1)
{
printf("$");

if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
{
printf("\n");
exit(0);
}

command[strcspn(command, "\n")] = '\0';

ptr = command + strlen(command) - 1;
while(ptr > command && isspace(*ptr))
    --ptr;
system(command);
ptr[1] = '\0';
{
}
if (strcmp(command, "ls -l") == 0)
{
  system("ls -l");
}
else if (strcmp(command, "ls") == 0)
{
  system("ls");
}
else if (strcmp(command, "exit") == 0)
{
exit(0);
}
}
pid = fork();
if (pid == 0) {
if (system(command) == -1)
{
perror("Error al ejecutar el comando");
exit(EXIT_FAILURE);
}
} else if (pid < 0)
{
perror("Error al crear el proceso hijo");
} else {
wait(NULL);
}
return 0;
}