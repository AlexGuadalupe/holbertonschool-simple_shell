#!/bin/bash

# Contributors
contributors=(
    "Alexandra Guadalupe <9035@holbertonstudents.com>"
    "Roger Rosado <Rogergbusiness34@gmail.com>"
    "Saul Vera <saul.vera787@gmail.com>"
)

# Function to generate README content
generate_readme() {
    cat << EOF
# Simple Shell Project

## Contributors
$(printf -- "- %s\n" "${contributors[@]}")

## Overview
This is a simple shell implementation written in C. It provides basic shell functionalities such as executing commands, handling environment variables, and searching for commands in the PATH.

## Files
- \`shell.h\`: Header file containing function prototypes, macro definitions, and necessary includes for the shell.
- \`func_build.c\`: Source file containing implementations of functions related to environment variables and string manipulation.
- \`search_path.c\`: Source file containing the implementation of a function to search for the full path of a command in the PATH environment variable.
- \`simple_shell.c\`: Main source file containing the implementation of the main shell loop and functions to handle commands.

## Compilation
To compile the shell, simply run the following command in your terminal:

\`\`\`bash
gcc -Wall -Werror -Wextra -pedantic *.c -o shell
\`\`\`

## Usage
After compilation, you can run the shell by executing the compiled binary:

\`\`\`bash
./shell
\`\`\`

Once the shell is running, you can enter commands just like in a regular shell. Some built-in commands are also available:
- \`env\`: Print the environment variables.
- \`exit\`: Exit the shell.

## Example
\`\`\`
$ ./shell
simple_shell$ ls
README.md  func_build.c  search_path.c  shell  shell.h  simple_shell.c
simple_shell$ env
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
PWD=/home/user/simple_shell
...
simple_shell$ exit
$
\`\`\`
EOF
}

