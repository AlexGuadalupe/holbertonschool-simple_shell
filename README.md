# Simple Shell Project

This is a simple shell project developed as part of a Holberton School curriculum. It provides a basic shell interface for users to execute commands.

## Contributors

- **Alexandra Guadalupe**
  - Email: 9035@holbertonstudents.com

- **Roger Rosado**
  - Email: Rogergbusiness34@gmail.com

- **Saul Vera**
  - Email: saul.vera787@gmail.com

## Description

The repository contains the following source and header files:

### shell.h

Header file containing function prototypes and macro definitions used throughout the shell program.

- **print_env**: Prints the environment variables.
- **str_cmp**: Compares up to a specified number of characters of two strings.
- **_getenv**: Retrieves the value of an environment variable.
- **main**: Entry point of the shell program.
- **read_command**: Reads and tokenizes user input.
- **print_not_found**: Prints a message when a command is not found in the PATH.
- **call_command**: Calls a command, handling execution using fork and execve.
- **execute_command**: Executes a command.
- **search_path**: Finds the full path of a command.

### func_build.c

Source file containing implementations of functions declared in shell.h.

- **print_env**: Implementation of printing environment variables.
- **str_cmp**: Implementation of string comparison function.
- **_getenv**: Implementation of retrieving environment variables.
- **search_path**: Implementation of finding the full path of a command.

### simple_shell.c

Source file containing the main function and implementations of functions declared in shell.h.

- **main**: Entry point of the shell program.
- **read_command**: Reads and tokenizes user input.
- **print_not_found**: Prints a message when a command is not found in the PATH.
- **call_command**: Calls a command, handling execution using fork and execve.
- **execute_command**: Executes a command.

### search_path.c

This file contains the implementation of a function search_path which is responsible for finding the full path of a command within the system's PATH environment variable.

- **search_path**:Implementation of finding the full path of a command.

## How to Use

To use the simple shell, compile the source files and run the resulting executable. The shell will provide a prompt where you can enter commands.

```bash
$ gcc -Wall -Werror -Wextra -pedantic *.c -o shell
$ ./shell

