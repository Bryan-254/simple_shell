#include "simple_shell.h"

/**
 * _printenv - This function will print environment like printenv
 *
 * Return: zero
 */

int _printenv(void)
{
	char *sp = environ[0];
	int x = 0;

	while (sp != NULL)
	{
		write(1, sp, _strlen(sp));
		write(1, "\n", 1);
		sp = environ[++x];
	}
	return (0);
}

/**
 * _str_ncmp - This function conducts a lexicographical comparison
 * @s1: This parameter is the first string
 * @s2: This parameter is the second string to compare to
 * @n: This parameter is the count of the comparison btwn s1 and s2
 * Return: -ve if s1 < s2, 0 if equal, +ve if s1 > s2
 * Description: This is src code file similar to GNU C library
 */

int _str_ncmp(char *s1, char *s2, int n)
{
	char currpos1, currpos2;

	while (n--)
	{
		currpos1 = *s1++;
		currpos2 = *s2++;
		if (currpos1 == '\0' || currpos1 != currpos2)
		{
			return (currpos1 < currpos2 ? -1 : (currpos1 > currpos2 ? 1 : 0));
		}
	}
	return (0);
}

/**
 * _getenv - This function will mimic and print environment like getenv
 * @var: This parameter is the environ variable
 *
 * Return: NULL
 */

char *_getenv(char *var)
{
	int x = 0;

	for (x = 0; environ[x]; x++)
	{
		if (_str_ncmp(environ[x], var, _strlen(var)) == 0)
		{
			return (&environ[x][_strlen(var)]);
		}
	}
	return (NULL);
}
