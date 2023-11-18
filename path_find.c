#include "shell.h"

/**
 * if_command_path - this checks if the command exist.
 * @command: the command being checked.
 * Return: NULL
 */


char *if_command_path(char *command)
{
	if (strchr(command, '/') != NULL)
	{
		char *direct_path = strdup(command);
		if (access(direct_path, X_OK) == 0)
		{
			return (direct_path);
		}
		free(direct_path);
	}
	else
	{
		char *path = getenv("PATH");
		char *path_copy = strdup(path);
		char *dir = strtok(path_copy, ":");

		while (dir != NULL)
		{
			size_t len = strlen(dir) + 1 + strlen(command) + 1;
			char *command_path = malloc(len);

			if (command_path == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}

			strcpy(command_path, dir);
			strcat(command_path, "/");
			strcat(command_path, command);

			if (access(command_path, X_OK) == 0)
			{
				free(path_copy);
				return (command_path);
			}

			free(command_path);
			dir = strtok(NULL, ":");
		}
		free(path_copy);
	}
	return (NULL);
}
