#include "shell.h"

/**
 * my_strcmp - Compare two strings
 * @s1: The first string to compare
 * @s2: The second string to compare
 *
 * Return: Negative value if s1 is less than s2,
 *         Positive value if s1 is greater than s2,
 *         0 if s1 is equal to s2
 */
int my_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}

/**
 * find_command_path - Find the full path of a command in the PATH environment
 * variable
 * @command: The command to find
 * @env: The environment variable array
 *
 * Return: Pointer to the full path of the command if found, NULL otherwise
 */
char *find_command_path(char *command, char **env)
{
	char *path = my_getenv(env, "PATH");
	char path_copy[4096];
	char *dir;
	static char full_command[4096];

	my_strcpy(path_copy, path);

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		my_strcpy(full_command, dir);
		my_strcat(full_command, "/");
		my_strcat(full_command, command);
		if (access(full_command, F_OK | X_OK) == 0)
		{
			return (full_command);
		}
		dir = strtok(NULL, ":");
	}

	return (NULL);
}

/**
 * get_full_command - Retrieves the full command path.
 * @command: The command string.
 * @env: The environment variables.
 * Return: A pointer to the full command path.
 */
char *get_full_command(char *command, char **env)
{
	char *full_command = NULL;

	if (command[0] == '/')
	{
		full_command = command;
	}
	else
	{
		full_command = find_command_path(command, env);
	}

	return (full_command);
}
/**
 * execute_command - Executes a command with the given arguments and
 * environment.
 * @command: The command to execute.
 * @args: The arguments for the command.
 * @env: The environment variables.
 * @prgm_name: The name of the program.
 */
void execute_command(char *command, char **args, char **env, char *prgm_name)
{
	char *full_command = get_full_command(command, env);
	pid_t pid;
	int status;

	if (full_command == NULL || access(full_command, F_OK | X_OK) != 0)
	{
		write(STDERR_FILENO, prgm_name, my_strlen(prgm_name));
		write(STDERR_FILENO, ": No such file or directory\n", 28);
		return;
	}
	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(full_command, args, env) == -1)
		{
			perror(prgm_name);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
	}
}
