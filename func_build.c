#include "shell.h"

/**
 * print_env - Prints the environment variables.
 * This function does not take any parameters and does not return a value.
 */

void print_env(void)
{
	char *s = environ[0];
	int i = 0;

	while (s)
	{
		write(1, s, strlen(s));
		write(1, "\n", 1);
		s = environ[++i];
	}
	return (0);
}

/**
 * str_cmp - Compares up to n characters of two strings.
 * @string1: The first string to compare.
 * @string2: The second string to compare.
 * @num_chars: The maximum number of characters to compare.
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 */

int str_cmp(char *string1, const char *string2, int num_chars)
{
	char c1, c2;

	while (n--)
	{
		c1 = *string1++;
		c2 = *string2++;
		if (c1 == '\0' || c1 != c2)

			return (c1 > c2 ? 1 : (c1 < c2 ? -1 : 0));
	}
	return (0);
}

/**
 * _getenv - Retrieves the value of an environment variable.
 * @env_var: The name of the environment variable to retrieve.
 * Return: A pointer to a string containing the value of the
 * environment variable,
 * or NULL if the environment variable does not exist.
 */

char *_getenv(const char *env_var)
{
	int i = 0;

	for (i = 0; environ[i]; i++)
	{
		if (_str_n_cmp(environ[i], var, strlen(env_var)) == 0)
			return (&environ[i][strlen(env_var)]);
	}
	return (NULL);
}

