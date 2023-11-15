#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

int _printenv(void);
int _str_ncmp(char *s1, char *s2, int n);
char *_getenv(char *var);
char *pathfinder(char *cmd);
int main(int argc, char *argv[]);
int cmd_read(char *st, size_t __attribute__((unused))getline_retval);
void print_cmdnotfound(char *cmd);
int call_thecommand(char *cmd_array[]);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strdup(char *st);

#endif
