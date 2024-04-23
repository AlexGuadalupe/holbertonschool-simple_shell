#include "shell.h"

/* 
*   Function: hsh_tokenizer
*   Parameters: char *input - the string to be tokenized
*   Return: char ** - array of tokens
*   
*   This function tokenizes the input string based on a specific delimiter and returns an array of tokens.
*   Allocate memory for tokens array
*   Tokenize the input string
*   Store token in tokens array
*   Check if buffer needs to be resized
*   Get next token
*   Set the last element of tokens array to NULL
*/
char **hsh_tokenizer(char *input)
{
	int buffer = BUFSIZE, newBuffer = 0, position = 0;
	char **tokens = NULL, *token = NULL;
	char **backup_tokens = NULL;

	
	tokens = malloc(buffer * sizeof(char *));
	if (tokens == NULL)
	{
		fprintf(stderr, "memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	
	token = strtok(input, DELIM_I);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		
		if (position >= buffer)
		{
			newBuffer = BUFSIZE * 2;
			backup_tokens = tokens;
			tokens = _realloc(tokens, buffer, newBuffer * sizeof(char *));
			if (tokens == NULL)
			{
				free(backup_tokens);
				free(tokens);
				fprintf(stderr, "memory allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		
		token = strtok(NULL, DELIM_I);
	}
	
	tokens[position] = NULL;
	return (tokens);
}

/** 
*  Function: tokenizer_path
*  Parameters: char *input - the string to be tokenized
*  Return: char ** - array of tokens
*  
* This function tokenizes the input string based on a different delimiter than the hsh_tokenizer function and returns an array of tokens.
*
* Allocate memory for tokens array
* Tokenize the input string
* Store token in tokens array
* Check if buffer needs to be resized
* Get next token
* Set the last element of tokens array to NULL
*/ 
char **tokenizer_path(char *input)
{
	int buffer = BUFSIZE, newBuffer = 0, position = 0;
	char **tokens = NULL, *token = NULL;
	char **backup_tokens = NULL;

	
	tokens = malloc(buffer * sizeof(char *));
	if (tokens == NULL)
	{
		fprintf(stderr, "memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	
	token = strtok(input, DELIM_P);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		
		if (position >= buffer)
		{
			newBuffer = BUFSIZE * 2;
			backup_tokens = tokens;
			tokens = _realloc(tokens, buffer, newBuffer * sizeof(char *));
			if (tokens == NULL)
			{
				free(backup_tokens);
				free(tokens);
				fprintf(stderr, "memory allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		
		token = strtok(NULL, DELIM_P);
	}
	
	tokens[position] = NULL;
	return (tokens);
}
