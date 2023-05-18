#include "shell.h"

/**
 * my_getenv - Get the value of an environment variable
 * @env: The environment variable array
 * @name: The name of the environment variable
 *
 * Return: The value of the environment variable if found, NULL otherwise
 */
char *my_getenv(char **env, char *name)
{
	size_t len = my_strlen(name);
	char **envp;

	for (envp = env; *envp != 0; envp++)
	{
		if (my_strncmp(*envp, name, len) == 0 && (*envp)[len] == '=')
		{
			return (*envp + len + 1);
		}
	}
	return (NULL);
}

/**
 * my_strncmp - compares the first n bytes of two strings
 *
 * @s1: the first string to compare
 * @s2: the second string to compare
 * @n: the number of bytes to compare
 *
 * Return: an integer value
 */

int my_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 != *s2)
		{
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		}
		else if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (0);
}

/**
 * my_strlen - calculate the length of a string
 *
 * @s: the string to calculate the length of
 *
 * Return: the length of the string
 */
size_t my_strlen(const char *s)
{
	size_t len = 0;

	while (*s++)
	{
		len++;
	}
	return (len);
}

/**
 * my_strcpy - copy a string
 *
 * @dest: the destination string
 * @src: the source string
 */
void my_strcpy(char *dest, const char *src)
{
	while ((*dest++ = *src++))
		;
}

/**
 * my_strcat - concatenate two strings
 *
 * @dest: the destination string
 * @src: the source string
 */
void my_strcat(char *dest, const char *src)
{
	my_strcpy(dest + my_strlen(dest), src);
}
