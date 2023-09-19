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
 * _input - function allocates memory for a character buffer
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
	{
		str[str_read - 1] = '\0';
	}
	return (str);
}
