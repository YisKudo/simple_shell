#include "shell.h"

/**
 * _atoi - converts a string to an integer.
 * @s: input string.
 * Return: integer.
 */
int _atoi(char *s)
{
	 /* initialize sign and result to 0 */
	unsigned int sign = 0, result = 0;
	/* if character in string is a minus sign, increment sign */
	while (*s)
	{
		if (*s == '-')
			sign++;
		/* if character is between 0 and 9, multiply result by 10 */
		if (*s >= '0' && *s <= '9')
		{
			result *= 10;
			/* add character to result */
			result += *s - '0';
		}
		/* if result is not 0, break */
		else if (result)
			break;
		s++;
	}
	/* if sign is odd, multiply result by -1 */
	if (sign % 2)
		result *= -1;
	return (result);
}
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

	if (trimmed_length == 0 || trimmed_input[0] == '#')
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

