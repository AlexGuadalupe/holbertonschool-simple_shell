#include "shell.h"

/**
*   Function: validate_input
*   Parameters: char **arguments - array of arguments, char **argv - array of program arguments (unused)
*   Return: char * - validated input or error message
*   
*   This function validates the input arguments and checks if the specified file exists in the system.
*
*   Check if the argument specifies an absolute or relative path
*   Check if the file exists
*   Get the PATH environment variable
*   Tokenize the PATH variable
*   Iterate through each directory in PATH
*   Concatenate "/" with the argument to form a path
*   Check if the file exists in the current directory
*   Free memory and return the validated input
*   Free memory and print error message if file not found
*/
char *validate_input(char **arguments, char **argv __attribute__((unused)))
{
	char *new_arguments, *first, *slash_argument = "/";
	char **tokens_path, holder_env[1024];
	int i = 0;

	if (arguments[0][0] == '/' || arguments[0][0] == '.') 
	{
		new_arguments = arguments[0];
		if ((access(new_arguments, F_OK) == -1)) 
		{
			fprintf(stderr, "%s: No such file or directory\n", arguments[0]);
			return ("Fail access");
		}
	}
	else
	{
		strcpy(holder_env, getenv("PATH"));
		tokens_path = tokenizer_path(holder_env);
		while (tokens_path[i])
		{
			
			first = str_concat(slash_argument, arguments[0]);
			new_arguments = str_concat(tokens_path[i], first);
			if ((access(new_arguments, F_OK) == -1))
			{
				free(new_arguments);
				free(first);
			}
			else
			{
				free(tokens_path);
				free(first);
				return (new_arguments);
			}
			i++;
		}
		free(tokens_path);
		fprintf(stderr, "%s: No such file or directory\n", arguments[0]);
		return ("Fail access");
	}
	return (new_arguments);
}

/* 
*   Function: validate_spaces
*   Parameters: char *input - input string
*   Return: int - flag indicating presence of spaces
*   
*   This function validates if the input string contains only spaces, tabs, or newlines.
*   Skip leading spaces, tabs, and newlines
*   If the string is not entirely spaces, tabs, or newlines, set flag to 0
*/
int validate_spaces(char *input)
{
	int i = 0, flag = 1, len = 0;

	len = strlen(input);

	while (input[i] == ' ' || input[i] == '\n' || input[i] == '\t')
		i++;

	if (i != len)
		flag = 0;
	return (flag);
}
