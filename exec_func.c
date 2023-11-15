#include "shell.h"

/**
 * exec_func - perform command
 *
 * @argv: commands and options in array of strings
 * @path: paths from env variables
 * @prog: the name of the program
 * Return: return 0
 */
int exec_func(char **argv, char **path, char *prog)
{
	int i;
	char *check_path;
	struct stat st;

	command command_struct[] = {
		{"exit", _exitprog},
		{"cd", _cd},
		{"help", _help},
		{"env", print_env},
		{"others", fork_wait_exec},
	};

	check_path = commandpath(argv[0], path);

	for (i = 0; i < 5; i++)
	{
		if (strcmp(argv[0], command_struct[i].buf) == 0)
		{
			command_struct[i].execute(argv);
			break;
		}

		if (i == 4)
		{
			if (argv[0][0] == '.' || argv[0][0] == '/')
			{
				if (stat(argv[0], &st) == 0)
				{
					command_struct[i].execute(argv);
					break;
				}
				else
					check_path = NULL;
			}

			if (check_path != NULL)
			{
				argv[0] = check_path;
				command_struct[i].execute(argv);
			}
			else
			{
				write(STDERR_FILENO, prog, _strlen(prog));
				write(1, " : ", 4);
				write(1, argv[0], _strlen(argv[0]));
				write(1, " : not found\n", 14);
			}
		}
	}

	free(check_path);

	return (0);
}
