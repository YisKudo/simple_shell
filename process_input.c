#include "shell.h"

/**
 * process_input - Process user input
 *
 * @input: Pointer to the input string
 * @env: Array of environment variables
 * @argv: Array of command-line arguments
 */
void process_input(char *input, char *argv[], char **env)
{
	char *trimmed_input;
	size_t trimmed_length;
	char *args[MAX_INPUT_LENGTH];
	int i;

	/* Trim leading and trailing spaces */
	trimmed_input = input;
	while (*trimmed_input == ' ')
	{
		trimmed_input++;
	}
	trimmed_length = my_strlen(trimmed_input);
	while (trimmed_length > 0 && trimmed_input[trimmed_length - 1] == ' ')
	{
		trimmed_input[trimmed_length - 1] = '\0';
		trimmed_length--;
	}

	if (trimmed_length == 0)
	{
		return; /* Ignore empty input */
	}

	tokenize_input(trimmed_input, args);

	handle_exit_command(args, input);

	if (my_strcmp(args[0], "env") == 0)
	{
		for (i = 0; env[i]; i++)
		{
			write(STDOUT_FILENO, env[i], my_strlen(env[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
	}
	else
	{
		execute_command(args[0], args, env, argv[0]);
	}
}

