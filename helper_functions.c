#include "shell.h"

/**
 * Signal handler for SIGINT (Ctrl+C)
 * Writing prompt after Ctrl+C interruption
 */
void sigintH(int signum)
{
	if (signum == SIGINT)
	{
		write(2, "\n#(ಠ_ಠ)->$ ", 14);
	}
}

/**
 * Function to concatenate two strings
 * Pointer to the concatenated string
 * Index variables
 * If either string is NULL, set it to an empty string
 * Calculating length of the two string
 * Increase length by 1 to accommodate null terminator
 * Allocating memory for the concatenated string
 * Return NULL if malloc fails
 */
char *str_concat(char *s1, char *s2)
{
	char *s;
	unsigned int i;
	unsigned int j;
	unsigned int k;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i] != '\0'; i++)
		continue;

	for (j = 0; s2[j] != '\0'; j++)
		continue;

	j = j + 1;

	s = malloc((i + j) * sizeof(char));

	if (s == NULL)
		return (0);

	for (k = 0; k < (i + j) ; k++)
	{
		if (k < i)
			s[k] = s1[k];
		if (k >= i)
			s[k] = s2[k - i];
	}
	return (s);
}

/**
 * Custom reallocation function
 * Pointer to the reallocated memory
 * Casted pointer for manipulation
 * Index variable
 * Cast the pointer to char*
 * If ptr is NULL, allocate memory of new_size
 * If new_size is 0 and ptr is not NULL, free ptr and return NULL
 * If old_size equals new_size, return ptr
 * Allocate memory for the reallocated memory
 * Free s if malloc fails
 * Copy contents of ptr to the reallocated memory
 * Free the original memory
 * Return the reallocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *s;
	char *ptr1;
	unsigned int i;

	ptr1 = (char *)ptr;

	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);

	s = malloc((new_size) * sizeof(char));
	if (s == NULL)
	{
		free(s);
		return (NULL);
	}

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			s[i] = ptr1[i];
	}
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			s[i] = ptr1[i];
	}
	free(ptr1);
	return (s);
}
