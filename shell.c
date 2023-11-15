#include "shell.h"

/**
 * handle_sigkill - Prevents the shell from exiting using ctrl C
 * @sig: Ctrl C signal
 *
 * Return: Nothing
 */
void handle_sigkill(__attribute__((unused)) int sig)
{
	signal(SIGINT, handle_sigkill);
}

/**
 * main - Creates a unix command line interpreter
 * @argc: Number function arguments
 * @argv: Arguments passed to the main function
 *
 * Return: Always 0 (success)
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	char *commands, *exit_cond = "exit";
	char **path;
	char *prog;
	size_t bytes_read = 1;
	ssize_t chars_read;

	signal(SIGINT, handle_sigkill);

	path = getpath();
	prog = argv[0];
	if (!isatty(STDIN_FILENO))
	{
		non_interactive(path, prog);
		exit(0);
	}
	while (1 && argc == 1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		commands = malloc(sizeof(char *));
		chars_read = getline(&commands, &bytes_read, stdin);
		if (chars_read == -1)
			perror("Error: Could not read file_stream");
		if (commands[0] == '\n')
			continue;
		commands[_strlen(commands) - 1] = '\0';
		argv = _strtok(commands, " \t");
		if (_strcmp(argv[0], exit_cond) == 0)
			break;
		exec_func(argv, path, prog);
		free(commands);
		free(argv);
	}
	free(path);
	if (commands != NULL)
		free(commands);
	if (argv != NULL)
		free(argv);

	return (0);
}
