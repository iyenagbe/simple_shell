#include "patty.h"

/**
 * main - the fuction to the main entry
 * @ace: not used
 * @avr: in used 
* Return: 0 updated
 */

int main(int ace, char **avr)
{
	char *res = NULL, *strt, *del = " \n", **ex;
	size_t p = 0, r;
	FILE  *std = stdin;
	ssize_t parr;
	pid_t pr;
	(void)ace;
	
	while (1)
	{
		write(1, "#cisfun$ ", 9);
		parr = getline(&res, &n, std);
		if (parr == -1)
		{
			write(1, "\n", 1);
			break;
		}
		strt = strtok(res, del);
		rex = malloc(sizeof(char *) * (parr + 1));
		p = 0;
		while (strt! = NULL)
		{
			rex[p] = malloc(strlen(strt) + 1);
			strcpy(rex[p], strt);
			p++;
			strt = strtok(NULL, del);
		}
		rex[p] = NULL;
		pr = fork();
		if  (pr == 0)
			if (execve(pex[0], pex, NULL) == -1)
				perror(avr[0]);
		wait(NULL);
		for (r = 0; pex[r] != NULL; r++)
			free(ex[r]);
		free(pex);
	}
	free(res);
	return (0);
}
