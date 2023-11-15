#include "patty.h"

/**
 * extrafunc - Execute a command using fork and execve.
 * @pex: array of strings representing the command and its arguments.
 * @res: array of strings representing the command-line arguments.
 */

void extrafunc(char **pex, char *res)
{
	int r;

	if (_strcmp(pex[0], "exit") == 0)
	{
		free(res);
		free_memory(pex);
		exit(EXIT_SUCCESS);
	}
	if (_strcmp(pex[0], "env") == 0)
	{
		r = 0;

		while (environ[r] != NULL)
		{
			write(STDOUT_FILENO, environ[r], _strlen(environ[r]));
			write(STDOUT_FILENO, "\n", 1);
			r++;
		}
	}
}

/**
 * _strcmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: less than 0 if s1 is less than s2, 0 if they're equal,
 * more than 0 if s1 is greater than s2
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 * Return: the length of the string
 */

int _strlen(char *s)
{
	int strcount = 0;

	while (s[strcount] != '\0')
	{
		strcount++;
	}

	return (strcount);
}

/**
 * *_strcpy - copies the string pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed to by dest
 * @dest: pointer to the buffer in which we copy the string
 * @src: string to be copied
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int len = 0, r = 0;

	while (src[len] != '\0')
	{
		len++;
	}

	while (r < len)
	{
		dest[r] = src[r];
		r++;
	}
	dest[r] = '\0';

	return (dest);
}

/**
 * _strcat - concatenates two strings
 * @dest: string to append to
 * @src: string to add
 * Return: a pointer to the resulting string
 */

char *_strcat(char *dest, char *src)
{
	int f = 0, s = 0;

	while (dest[f] != '\0')
	{
		f++;
	}

	while (src[s] != '\0')
	{
		dest[f] = src[s];
		f++;
		s++;
	}
	dest[f] = '\0';
	return (dest);
}
