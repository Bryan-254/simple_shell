#include "shell.h"

/**
 * _strcmp - Compares two strings
 * @str_1: First string
 * @str_2: Second string
 *
 * Return: - (0) if the strings are equal
 *         - -1 if str_1 < str_2
 *         - 1 if str_1 > str_2
 */
int _strcmp(char *str_1, char *str_2)
{
	while ((*str_1 && *str_2) && (*str_1 == *str_2))
	{
		str_1++;
		str_2++;
	}

	if (*str_1 == *str_2)
		return (0);
	else
		return (*str_1 - *str_2);
}

/**
 * _strlen - Returns the length of a string
 * @str: String whose length is to be determined
 *
 * Return: length of the string
 */
unsigned int _strlen(char *str)
{
	unsigned int len = 0;

	while (str[len])
	{
		len++;
	}
	return (len);
}

/**
 * _strdup - Duplicates a string
 * @str: String to be duplicated
 *
 * Return: Pointer to newly allocated string duplicate
 */
char *_strdup(char *str)
{
	unsigned int i = 0;
	unsigned int len;
	char *str_dup;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);
	str_dup = malloc(sizeof(char) * (len + 1));
	if (str_dup == NULL)
		return (NULL);

	while (i < len)
	{
		str_dup[i] = str[i];
		i++;
	}

	str_dup[i] = '\0';

	return (str_dup);
}
