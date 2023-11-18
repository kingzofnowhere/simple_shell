#include "shell.h"

/**
 * show_prompt - This displays the prompt.
 */


void show_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		printf("$ ");
	}
}

/**
 * execute_command - it executes commands passed to the program.
 * @args: To be execute.
 * Return: 1 (success) otherwise return 0(fail).
 */


int execute_command(char **args)
{
	int status;
	pid_t pid;

	char *command_path = if_command_path(args[0]);

	while (command_path != NULL)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			free(command_path);
			return (1);
		}
		if (pid == 0)
		{
			if (execve(args[0], args, environ) == -1)
			{
				perror("args");
				fprintf(stderr, "Error executing %s\n", args[0]);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}
		free(command_path);
		return (0);
	}
	perror("./hsh");
	return (1);
}
