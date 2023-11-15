#include "shell.h"

/**
 * fork_wait_exec - executes commands
 * @argv: command to be executed
 *
 * Return: 0
 */
int fork_wait_exec(char **argv)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error: Failed to fork process!");
		free(argv);
		return (0);
	}

	if (child_pid == 0)
	{

		if (execve(argv[0], argv, NULL) == -1)
			perror("Error");
		/*free(argv);*/
		exit(0);

	}
	else
		wait(&status);
	/*free(argv);*/

	return (0);
}
