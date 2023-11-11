#include "patty.h"

/**
 * main - the fuction to the main entry
 * @ac: not used
 * @av: in used
 * Return: 0 updated
 */

int main(int ac, char **av)
{
	char *res = NULL, *strt, *del = "\n", **ex;
	size_t n = 0, r;
	FILE  *st = stdin;
	ssize_t arr;
	pid_t pr;
	(void)ac;

	while (1)
	{
		write(1, "#cisfun$ ", 9);
		arr = getline(&res, &n, st);
		if (arr == -1)
		{
		write(1, "\n", 1);
			break;
		}
		strt = strtok(res, del);
		ex = malloc(sizeof(char *) * (arr + 1));
		r = 0;
		while (strt != NULL)
		{
			ex[r] = malloc(strlen(strt) + 1);
			strcpy(ex[r], strt);
			r++;
			strt = strtok(NULL, del);
		}
		ex[r] = NULL;
		pr = fork();
		if (pr == 0)
		if (execve(ex[0], ex, NULL) == -1)
			perror(av[0]);
		wait(NULL);
		for (r = 0; ex[r] != NULL; r++)
			free(ex[r]);
	free(ex);
	}
	free(res);
	return (0);
}
