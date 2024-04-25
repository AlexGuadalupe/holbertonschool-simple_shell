#include "shell.h"

int _printenv(void)
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

int _str_n_cmp(char *s1, char *s2, int n)
{
	char c1, c2;

	while (n--)
	{
		c1 = *s1++;
		c2 = *s2++;
		if (c1 == '\0' || c1 != c2)
			/* compare at most, first n bytes of both strings */
			return (c1 > c2 ? 1 : (c1 < c2 ? -1 : 0));
	}
	return (0);
} 

char *_getenv(char *var)
{
	int i = 0;

	for (i = 0; environ[i]; i++)
	{
		if (_str_n_cmp(environ[i], var, strlen(var)) == 0)
			return (&environ[i][strlen(var)]);
	}
	return (NULL);
}

