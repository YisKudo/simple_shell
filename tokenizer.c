#include "shell.h"

/**
 * tokenize_input - Tokenize the input string into arguments
 * @input: The input string to tokenize
 * @args: The array to store the tokenized arguments
 */
void tokenize_input(char *input, char **args)
{
	int arg_count = 0;
	char *token = strtok(input, " ");
	char *end_quote_or_null;

	while (token)
	{
		if (token[0] == '"' && arg_count == 0)
		{
			args[arg_count++] = token + 1;
			end_quote_or_null = my_strchr(args[arg_count - 1], '"');
			if (end_quote_or_null)
			{
				*end_quote_or_null = '\0';
			}
			token = strtok(NULL, " ");
		}
		else if (token[0] == '"')
		{
			/* Handle quotes in the arguments */
			args[arg_count++] = token + 1;
			end_quote_or_null = my_strchr(args[arg_count - 1], '"');
			if (end_quote_or_null)
			{
				*end_quote_or_null = '\0';
			}
			token = strtok(NULL, " ");
		}
		else
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
	}
	args[arg_count] = NULL;
}

/**
 * handle_exit_command - Handles the exit command
 * @args: The array of arguments
 * @input: input string
 */
void handle_exit_command(char **args, char *input)
{
	if (args[0] != NULL && my_strcmp(args[0], "exit") == 0)
	{
		free(input);
		exit(EXIT_SUCCESS);
	}
}
