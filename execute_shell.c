#include "shell.h"

/**
 * execute_shell - Execute the shell program
 *
 * @env: the environment variables
 * @argv: the command-line arguments
 * @argc: the number of command-line arguments
 */
void execute_shell(int argc, char *argv[], char **env)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t bytes_read;

	if (argc != 1)
	{
		write(STDERR_FILENO, "Usage: simple_shell\n", 20);
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		/* Display prompt */
		display_prompt();

		/* Read input */
		bytes_read = getline(&input, &input_size, stdin);

		/* Handle end of file condition */
		if (bytes_read == -1)
		{
			if (isatty(fileno(stdin)))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			break;
		}

		/* Remove new line character */
		input[bytes_read - 1] = '\0';

		/* Process input */
		process_input(input, argv, env);
	}

	free(input);
}

/**
 * main - Entry point of the program
 *
 * @argc: the number of command-line arguments
 * @argv: an array of command-line argument strings
 * @env: the environment variables
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[], char **env)
{
	if (argc != 1)
	{
		write(STDERR_FILENO, "Usage: simple_shell\n", 20);
		exit(EXIT_FAILURE);
	}

	execute_shell(argc, argv, env);
	return (0);
}
