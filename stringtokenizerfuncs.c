#include "shell.h"

/**
 * _strtok - Breaks a string into a sequence of tokens
 * @str: String to be broken into tokens
 * @delim: The delimiter used for tokenizing the string
 *
 * Return: Array of the tokens
 */

char **_strtok(char *str, const char *delim)
{
	char *tokens;
	char **argv;
	int i = 0, array_size = 1024;

	/*printf("Before first strtok function\n");*/
	tokens = strtok(str, delim);
	/*printf("After first strtok function\n");*/
	argv = malloc(sizeof(char *) * array_size);
	if (argv == NULL)
		return (NULL);

	/*printf("Before strtok loop\n");*/
	if (tokens == NULL)
		return (NULL);
	while (tokens != NULL)
	{
		argv[i] = tokens;
		tokens = strtok(NULL, delim);
		i++;
		/*printf("Within strtok loop\n");*/
	}
	/*printf("After strtok loop\n");*/
	argv[i] = NULL;

	return (argv);
}
