#include "patty.h"

/**
 * _strncmp - compares two strings up to a specified number of characters
 * @s1: first string to compare
 * @s2: second string to compare
 * @n: maximum number of characters to compare
 *
 * Return: less than 0 if s1 is less than s2, 0 if they're equal,
 * more than 0 if s1 is greater than s2
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
while (n && *s1 && (*s1 == *s2))
	{
	s1++;
	s2++;
	n--;
	}

	return (n ? *s1 - *s2 : 0);
}
