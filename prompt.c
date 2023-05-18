#include "shell.h"

/**
 * display_prompt - Display the command prompt
 */
void display_prompt(void)
{
	if (isatty(fileno(stdin)))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
}

