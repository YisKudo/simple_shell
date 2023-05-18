#include "shell.h"

/**
 * my_strchr - Locate the first occurrence of a character in a string
 *
 * @s: Pointer to the null-terminated string to search
 * @c: The character to locate
 *
 * Return: Pointer to the first occurrence of the character in the string,
 *         or NULL if the character is not found
 */
char *my_strchr(char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s++)
		{
			return (NULL);
		}
	}
	return ((char *)s);
}

/**
 * my_strncpy - Copy a string to a specified length
 *
 * @dest: Pointer to the destination buffer
 * @src: Pointer to the source string
 * @n: Maximum number of characters to copy
 *
 * Return: Pointer to the destination buffer
 */
char *my_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}
