#ifndef _SHELL_H
#define _SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <errno.h>

#define MAX_INPUT 1024

extern char **environ;

size_t tokenize_input(char *command, char *tokens[]);
void show_prompt(void);
char *read_input(void);
int main(void);
int execute_command(char **args);
char *if_command_path(char *command);
void execute_env(void);
void execute_exit(void);

#endif
