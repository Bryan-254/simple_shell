#include "shell.h"

/**
 * getpath - get the paths of the system from the environment
 *           variables.
 *
 * Return: Pointer to the first node of the list
 */
char **getpath(void)
{
	int i = 0;
	/*extern char **environ;*/
	char **paths1;
	char **paths2;

	while (environ[i] != NULL)
	{
		if (environ[i][0] == 'P' && environ[i][1] == 'A' && environ[i]
		    [2] == 'T' && environ[i][3] == 'H')
		{
			paths1 = _strtok(environ[i], "=");

			paths2 = _strtok(paths1[1], ":");

			break;
		}
		i++;
	}

	free(paths1);
	return (paths2);
}

/**
 * commandpath - Find the path of a command
 * @command: Command entered
 * @path: Full path of the command
 *
 * Return: Full path of command if found, otherwise, return NULL
 */
char *commandpath(char *command, char **path)
{
	int i = 0;
	char *full;

	struct stat sb;



	while (path[i])
	{
		full = malloc(sizeof(char *) * 1024);
		if (full == NULL)
		{

			return (NULL);
		}

		strcpy(full, path[i]);
		full = strcat(full, "/");
		full = strcat(full, command);


		if (stat(full, &sb) == 0)
			return (full);

		i++;
		free(full);

	}


	return (NULL);
}
