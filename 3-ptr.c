#include "patty.h"

/**
 * execute_command - Execute a command using fork and execve.
 * @ex: array of strings representing the command and its arguments.
 * @av: array of strings representing the command-line arguments.
 */
void execute_command(char **ex, char **av)
{
	pid_t pr = fork();

	if (pr == 0)
	{
		if (execve(ex[0], ex, NULL) == -1)
			perror(av[0]);
	}
	else
	{
		wait(NULL);
	}
}

/**
 * find_path_in_environ - Find the PATH variable in the environ array.
 * @env: array of environment variables.
 * Return:rPATH variable value if found, otherwise NULL.
 */
char *find_path_in_environ(char **env)
{
	size_t r = 0;

	while (env[r] != NULL)
	{
		if (strncmp(env[r], "PATH=", 5) == 0)
		{
			return (env[r] + 5);
		}
		r++;
	}

	return (NULL);
}

/**
 * execute_with_path - Execute a command by
 * searching for it in the PATH variable.
 * @ex: array of strings representing the command and its arguments.
 * @av: array of strings representing the command-line arguments.
 */
void execute_with_path(char **ex, char **av)
{
	size_t r = 0;
	char *path, *strt1, **pathdel, *pathenv;


	pathenv = find_path_in_environ(environ);
	path = malloc(sizeof(char) * (strlen(pathenv) + 1));
	if (pathenv != NULL)
		strcpy(path, pathenv);
	strt1 = strtok(path, ":");
	pathdel = malloc(sizeof(char *) * (strlen(pathenv) + 1));

	while (strt1 != NULL)
	{
		pathdel[r] = malloc(strlen(strt1) + 2 + strlen(ex[0]));
		strcpy(pathdel[r], strt1);
		strcat(pathdel[r], "/");
		strcat(pathdel[r], ex[0]);

		if (access(pathdel[r], X_OK) == 0)
		{
			strcpy(ex[0], pathdel[r]);
			execute_command(ex, av);
		}
		r++;
		strt1 = strtok(NULL, ":");
	}
	pathdel[r] = NULL;
	if (pathdel != NULL)
	{
		for (r = 0; pathdel[r] != NULL; r++)
			free(pathdel[r]);
		free(pathdel);
	}
	if (path != NULL)
		free(path);

}

/**
 * free_memory - Free dynamically allocated memory.
 * @ex: array of strings to be freed.
 */
void free_memory(char **ex)
{
	size_t r;

	if (ex[0] != NULL)
		for (r = 0; ex[r] != NULL; r++)
			free(ex[r]);

	if (ex != NULL)
		free(ex);
}

/**
 * main - the function to the main entry point
 * @ac: not used
 * @av: in used
 * Return: 0 updated
 */

int main(int ac, char **av)
{
	char *res = NULL, *strt, *del = " \n", **ex;
	size_t n = 0, r;
	FILE  *st = stdin;
	ssize_t arr;
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
			ex[r] = malloc(sizeof(char *) * (strlen(strt) + 1));
			strcpy(ex[r], strt);
			r++;
			strt = strtok(NULL, del);
		}
		ex[r] = NULL;
		if (access(ex[0], X_OK) == 0)
			execute_command(ex, av);

		if (access(ex[0], X_OK) == -1)
		{
			execute_with_path(ex, av);
		}
		free_memory(ex);
	}
	if (res != NULL)
		free(res);
	return (0);
}
