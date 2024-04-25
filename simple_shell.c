#include "shell.h"

/**
 * main - imprime el prompt, maneja EOF, lee file_stream
 * @argc: contador de argumentos (no necesario)
 * @argv: argv para el comando
 * Return: Siempre devuelve 0.
 */
int main(int argc, char *argv[])
{
    char *input = NULL;
    size_t buffer_size = 0;
    ssize_t file_stream = 0;
    char *program_name = argv[0];

    (void)argc;

    while (1)
    {
        if (isatty(STDIN_FILENO) == 1)
            write(1, "simple_shell$ ", 13);
        file_stream = getline(&input, &buffer_size, stdin);
        if (file_stream == -1)
        {
            if (isatty(STDIN_FILENO) == 1)
                write(1, "\n", 1);
            break;
        }

        if (input[file_stream - 1] == '\n')
            input[file_stream - 1] = '\0';
        if (*input == '\0')
            continue;
        if (read_command(input, file_stream, program_name) == 2)
        {
            free(input);
            exit(EXIT_SUCCESS);
        }
    }
    free(input);
    input = NULL;
    return (0);
}

/**
 * read_command - maneja la línea de comando y la tokeniza
 * @input: string
 * @file_stream: entrada de getline
 * @program_name: nombre del programa
 * Return: 0
 */
int read_command(char *input, size_t __attribute__((unused)) file_stream, char *program_name)
{
    char *token = NULL;
    char *cmd_arr[100];
    int i;

    if (input == NULL)
        return (0);

    if (strcmp(input, "exit") == 0)
        return (2);

    if (strcmp(input, "env") == 0)
        print_env();

    token = strtok(input, " "), i = 0;
    while (token)
    {
        cmd_arr[i++] = token;
        token = strtok(NULL, " ");
    }
    if (i == 0)
        return (0);

    cmd_arr[i] = NULL;
    return (call_command(cmd_arr, program_name));
}

/**
 * print_not_found - imprime cuando el comando no se encuentra en el PATH
 * @cmd: una cadena proporcionada por stdin
 * @program_name: nombre del programa
 */
void print_not_found(char *cmd, char *program_name)
{
    fprintf(stderr, "%s: %s: comando no encontrado\n", program_name, cmd);
}

/**
 * call_command - llama al comando, hace fork, execve
 * @cmd_arr: una cadena proporcionada por stdin
 * @program_name: nombre del programa
 * Return: 0
 */
int call_command(char *cmd_arr[], char *program_name)
{
    char *cmd = cmd_arr[0];
    struct stat buf;
    char *exe_path_str = NULL;
    int result;

    if (cmd == NULL)
        return (0);

    if (cmd[0] == '/' || strncmp(cmd, "./", 2) == 0)
    {
        if (stat(cmd, &buf) == 0)
        {
            result = execute_command(cmd_arr, program_name);
            return (result);
        }
        else
        {
            print_not_found(cmd, program_name);
            return (3);
        }
    }

    exe_path_str = search_path(cmd);
    if (exe_path_str == NULL)
    {
        print_not_found(cmd, program_name);
        return (3);
    }

    cmd_arr[0] = exe_path_str;
    result = execute_command(cmd_arr, program_name);
    free(exe_path_str);
    return (result);
}

/**
 * execute_command - ejecuta el comando
 * @cmd_arr: una cadena proporcionada por stdin
 * @program_name: nombre del programa
 * Return: 0
 */
int execute_command(char *cmd_arr[], char *program_name)
{
    pid_t is_child;
    int status;

    is_child = fork();
    if (is_child < 0)
    {
        perror("Error:");
        return (-1);
    }
    if (is_child > 0)
    {
        wait(&status);
    }
    else if (is_child == 0)
    {
        execve(cmd_arr[0], cmd_arr, environ);
        perror(program_name);
        exit(1);
    }
    return (0);
}

