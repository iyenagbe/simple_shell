#include "patty.h"

/**
 * Executting commands using fork and execve.
 * @ex: The array of strings representing the command of its arguments.
 * @av: The array of strings representing the command-line arguments.
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
