#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

extern char **environ;

/**
 * struct command - A string - function pair
 *
 * @buf:  the command
 * @execute: Special function implemented to print data of a given
 * specifier to stdout
 *
 * Description: A specifier - function pair
 */
typedef struct command
{
	char *buf;
	int (*execute)(char **args);
} command;


/* string manipulator functions */
int _strcmp(char *str_1, char *str_2);
unsigned int _strlen(char *str);
char *_strdup(char *str);

/* string_tokenizing*/
char **_strtok(char *str, const char *delim);

/* getpath */
char **getpath(void);
char *commandpath(char *command, char **path);

/* built-in functions */
int _cd(char **args);
int _exitprog(char **args);
int _help(char **args);
int print_env(char **argv);

/* exec_func */
int exec_func(char **argv, char **paths, char *prog);

/* Non-interactive */
int non_interactive(char **path, char *prog);

/* fork_wait_exec function */
int fork_wait_exec(char **argv);

#endif /* !SHELL_H */
