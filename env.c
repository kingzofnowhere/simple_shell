#include "shell.h"

/**
 * execute_env - This prints the environment var.
 */


void execute_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
