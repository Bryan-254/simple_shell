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

char *_strdup(char *st);
int cmd_read(char *s, size_t __attribute__((unused))file_stream);
char *pathfinder(char *cmd);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
void print_not_found(char *cmd);
int call_command(char *cmd_arr[]);
char *_getenv(char *var);
int _str_ncmp(char *s1, char *s2, int n);
int _printenv(void);

#endif