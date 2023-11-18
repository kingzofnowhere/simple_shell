#include "shell.h"

/**
 * read_input - This reads a line from stdin.
 * Return: String containing the user input.
 */

char *read_input(void)
{
	char *input = NULL;
	size_t input_size = 0;

	ssize_t getline_output;
	size_t len;

	getline_output = getline(&input, &input_size, stdin);

	if (getline_output == -1)
	{
		free(input);
		if (feof(stdin))
		{
			return (NULL);
		}
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}

	len = strlen(input);

	if (len > 0 && input[len - 1] == '\n')
	{
		input[len - 1] = '\0';
	}
	if (len >= MAX_INPUT)
	{
		free(input);
		return (NULL);
	}
	return (input);
}
