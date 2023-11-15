#include "simple_shell.h"

/**
 * *_strcat- This function concatenates two strings.
 * @dest: This parameter is the string of destination
 * @src: This parameter is the string of source
 *
 * Return: Always 0.
 */

char *_strcat(char *dest, char *src)
{
	int x = 0;

	int leng = _strlen(dest);

	while (src[x] != '\0')
	{
		dest[leng] = src[x];
		leng++;
		x++;
	}
	dest[leng] = '\0';
	return (dest);
}

/**
 * _strcmp - This function compares two strings
 * @s1: This parameter is the first string
 * @s2: This parameter is the second string to compare to first string
 *
 * Return: -ve if s1 < s2, 0 if equal, +ve if s1 > s2
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * *_strcpy- This function copies a string
 * @dest: This parameter is the new string
 * @src: This parameter is the original string
 *
 * Return: Always 0.
 */

char *_strcpy(char *dest, char *src)
{
	int leng;
	int x;

	leng = _strlen(src);

	for (x = 0; x < leng; x++)
	{
		dest[x] = src[x];
	}
	dest[x] = '\0';

	return (dest);
}

/**
 * _strlen - This is a function that returns the string length.
 * @s: This parameter is the string to be checked
 *
 * Return: The string length
 */

int _strlen(char *s)
{
	int x;
	int str_count = 0;

	for (x = 0 ; s[x] != '\0' ; x++)
	{
		str_count++;
	}
	return (str_count);
}

/**
 * *_strdup - This function copies the input string
 * @st: This parameter is the input string
 *
 * Return: Pointer to the duplicated string or NULL if error occurs
 */

char *_strdup(char *st)
{
	char *dupli;
	unsigned int x = 0, leng = 0;

	if (st == NULL)
	{
		return (NULL);
	}

	while (str[leng])
	{
		leng++;
	}

	dupli = malloc(sizeof(char) * (leng + 1));

	if (!dupli)
	{
		return (NULL);
	}

	while ((dupli[x] = st[x]) != '\0')
	{
		x++;
	}

	return (dupli);
}
