#include "patty.h"

/**
 * execute_command - Execute a command using fork and execve.
 * @pex: array of strings representing the command and its arguments.
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
 * Return: PATH variable value if found, otherwise NULL.
 */
char *find_path_in_environ(char **env)
{
	size_t r = 0;

	while (env[r] != NULL)
	{
		if (_strncmp(env[r], "PATH=", 5) == 0)
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
	path = malloc(sizeof(char) * (_strlen(pathenv) + 1));
	if (pathenv != NULL)
		_strcpy(path, pathenv);
	strt1 = strtok(path, ":");
	pathdel = malloc(sizeof(char *) * (_strlen(pathenv) + 1));

	while (strt1 != NULL)
	{
		pathdel[r] = malloc(_strlen(strt1) + 2 + _strlen(ex[0]));
		_strcpy(pathdel[r], strt1);
		_strcat(pathdel[r], "/");
		_strcat(pathdel[r], ex[0]);

		if (access(pathdel[r], X_OK) == 0)
		{
			_strcpy(ex[0], pathdel[r]);
			execute_command(ex, av);
			break;
		}
		r++;
		strt1 = strtok(NULL, ":");
	}
	if (strt1 == NULL)
	{
		write(2, av[0], strlen(av[0]));
		write(2, ": No such file or directory\n", 28);
	}
	r++;
	pathdel[r] = NULL;
	free_memory(pathdel);
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
	{
		for (r = 0; ex[r] != NULL; r++)
			free(ex[r]);
	}
	if (ex != NULL)
		free(ex);
}

/**
 * main - the function to main entry point
 * @ac: not used
 * @av: in used
 * Return: 0 updated
 */

int main(int ac, char **av)
{
	char *res = NULL, *strt, *del = " \n", **ex;
	size_t n = 0, r;
	ssize_t arr;
	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "#cisfun$ ", 9);
		arr = getline(&res, &n, stdin);
		if (arr == -1 && isatty(STDIN_FILENO))
		{
			write(1, "\n", 1);
			break;
		}
		else if (arr == -1)
			break;
		strt = strtok(res, del);
		ex = malloc(sizeof(char *) * (arr + 1));
		r = 0;
		while (strt != NULL)
		{
			ex[r] = malloc(sizeof(char *) * (_strlen(strt) + 1));
			_strcpy(ex[r], strt);
			r++;
			strt = strtok(NULL, del);
		}
		ex[r] = NULL;
		extrafunc(ex, res);
		if (access(ex[0], X_OK) == 0)
			execute_command(ex, av);
		if (access(ex[0], X_OK) == -1)
			execute_with_path(ex, av);
		free_memory(ex);
	}
	if (res != NULL)
		free(res);
	return (0);
}
