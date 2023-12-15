#ifndef SHELL_H
#define SHELL_H

/*---LIBRARIES---*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

/*---MACROS---*/
#define TOK_DELIM " \n"

void shell_interactive(void);
void shell_inactive(void);
char *read_stream(void);
char *read_line(void);
char **split_line(char *line);
char *get_path(char *command);
int exec_arg(char **args);
#endif
