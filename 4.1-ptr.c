#include "patty.h"

/**
 * extrafunc - Execute a command using fork and execve.
 * @ex: rray of strings representing the command and its arguments.
 * @av: array of strings representing the command-line arguments.
 */

void extrafunc(char **ex, char *res)
{
	if (strcmp(ex[0], "exit") == 0)
	{
		free(res);
		free_memory(ex);
		exit(EXIT_SUCCESS);
	}
}
