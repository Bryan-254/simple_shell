#include "shell.h"

/**
 * pathfinder - Function takes PATH string, tokenizes the sting,
 * then concatenates with "/" & cmd
 * @cmd: This parameter is command passed from getline in main
 *
 * Return: new_path for use in cmd_read
 */

char *pathfinder(char *cmd)
{
	char *pathVar = _strdup(_getenv("PATH"));
	int x = 0, y = 0;
	char *token_pathstr = strtok(path, ":");
	char *path_arr[100];
	char *s2 = cmd;
	char *new_pathVar = NULL;
	struct stat buf;

	new_pathVar = malloc(sizeof(char) * 100);
	if (_getenv("PATH")[0] == ':')
	{
		if (stat(cmd, &buf) == 0)
			return (_strdup(cmd));
	}
	while (token_pathstr != NULL)
	{
		path_arr[x++] = token_pathstr;
		token_pathstr = strtok(NULL, ":");
	}
	path_arr[x] = NULL;
	for (y = 0; path_arr[y]; y++)
	{
		_strcpy(new_pathVar, path_arr[y]);
		_strcat(new_pathVar, "/");
		_strcat(new_pathVar, s2);
		_strcat(new_pathVar, "\0");
		if (stat(new_pathVar, &buf) == 0)
		{
			free(pathVar);
			return (new_pathVar);
		}
		else
			new_pathVar[0] = 0;
	}
	free(pathVar);
	free(new_pathVar);
	if (stat(cmd, &buf) == 0)
		return (_strdup(cmd));
	return (NULL);
}
