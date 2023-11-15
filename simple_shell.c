#include "shell.h"
char *name;

/**
 * main - Function will print prompt, handle End of File & read getline_retval
 * @argc: This parameter is the arg count (not needed hence void attached)
 * @argv: This parameter is the argv for command
 * Return: zero
 */

int main(int argc, char *argv[])
{
	char *input_buffer = NULL;
	size_t sizeof_buffer = 0;
	ssize_t getline_retval = 0;

	(void) argc;
	name = argv[0];

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			write(1, "$ ", 2);
		}
		getline_retval = getline(&input_buffer, &sizeof_buffer, stdin);
		if (getline_retval == -1)
		{
			if (isatty(STDIN_FILENO) == 1)
			{
				write(1, "\n", 1);
			}
			break;
		}

		if (input_buffer[getline_retval - 1]  == '\n')
		{
			input_buffer[getline_retval - 1]  = '\0';
		}
		if (*input_buffer == '\0')
		{
			continue;
		}
		if (cmd_read(input_buffer, getline_retval) == 2)
		{
			break;
		}
	}
	free(input_buffer);
	input_buffer = NULL;
	return (0);
}

/**
 * cmd_read - This function the handles command line and then tokenizes it
 * @st: This parameter is the string
 * @getline_retval: This parameter is the getline input
 * Return: results of call_thecommand function
 */

int cmd_read(char *st, size_t __attribute__((unused))getline_retval)
{
	char *curr_arg = NULL;
	char *cmd_array[100];
	int x;

	if (_strcmp(st, "exit") == 0)
	{
		return (2);
	}
	if (_strcmp(st, "env") == 0)
	{
		return (_printenv());
	}
	curr_arg = strtok(st, " "), x = 0;

	while (curr_arg)
	{
		cmd_array[x++] = curr_arg;
		curr_arg = strtok(NULL, " ");
	}
	cmd_array[x] = NULL;
	return (call_thecommand(cmd_array));
}

/**
 * print_cmdnotfound - This function will print when cmd is not found in path
 * @cmd: This function is a string provided by the stdin
 * Return: nothing
 */

void print_cmdnotfound(char *cmd)
{
	write(2, name, _strlen(name));
	write(2, ": 1: ", 5);
	write(2, cmd, _strlen(cmd));
	write(2, ": not found\n", 12);
}

/**
 * call_thecommand - This function will call cmd, forks, execve
 * @cmd_array: This parameter is a string provided by the stdin
 * Return: 0
 */

int call_thecommand(char *cmd_array[])
{
	char *str_of_exepath = NULL;
	char *cmd = NULL;
	pid_t child_pid;
	int status_exit;

	cmd = cmd_array[0];
	str_of_exepath = pathfinder(cmd);

	if (str_of_exepath == NULL)
	{
		print_cmdnotfound(cmd);
		return (3);
	}
	child_pid = fork();
	if (child_pid < 0)
	{
		perror("Error:");
		return (-1);
	}
	if (child_pid > 0)
	{
		wait(&status_exit);
	}
	else if (child_pid == 0)
	{
		(execve(str_of_exepath, cmd_array, environ));
		perror("Error:");
		exit(1);
	}
	free(str_of_exepath);
	return (0);
}
