#include "shell.h"

/**
 * _prompt - prints the $ prompt
 * Return: void
 */
void _prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "JDshell$ ", 9);
	fflush(stdout);
}

/**
 * _input - reads user input
 * Return: void
 */
char *_input(void)
{
	char *str = NULL;
	size_t str_size = 0;
	ssize_t str_read = getline(&str, &str_size, stdin);

	if (str_read == -1)
	{
		free(str);
		return (NULL);
	}
	if (str_read > 0 && str[str_read - 1] == '\n')
		str[str_read - 1] = '\0';
	return (str);
}

/**
 * _setunsetenv - handles setting and unsetting envs
 * @tokens: array
 * Return: 0 or -1
 */
innt _setunsetenv(char **tokens)
{
	if (tokens[1] == NULL || tokens[2] == NULL)
	{
		_print("Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}
	if (_strcmp(tokens[0], "setenv") == 0)
	{
		if (_setenv(tokens[1], tokens[2], 1) == -1)
		{
			perror("setenv failed");
			return (-1);
		}
	}
	else if
	{
		if (_unsetenv(tokens[1]) == -1)
		{
			perror("unsetenv failed");
			return (-1);
		}
	}
	return (0);
}
