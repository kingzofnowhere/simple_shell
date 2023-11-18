#include "shell.h"

/**
 * main - The entry point.
 * Return: 0
 */


int main(void)
{
	char *token;
	char *args[MAX_INPUT];
	int i = 0;
	char *input = NULL;
	size_t input_size = 0;

	show_prompt();

	while (getline(&input, &input_size, stdin) != -1)
	{
		if (*input == '\n')
		{
			show_prompt();
			continue;
		}

		i = 0;

		token = strtok(input, " \n\t\r");

		while (token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, " \n\t\r");
			i++;
		}
		args[i] = NULL;

		if (args[0] == NULL)
		{
			show_prompt();
			continue;
		}

		if (strcmp(args[0], "exit") == 0)
		{
			free(input);
			exit(0);
		}
		else
		{
			execute_command(args);
		}
		show_prompt();
	}
    
	return (0);
}
