#include "shell.h"

/**
 * handlesigs - handles keyboard interrupt signals Ctrl+c Ctrl+D
 * @sig: sig int
 * Return: void
 */
void handlesigs(int sig)
{
	if (sig == SIGINT)
		_print("\nJDshell$ ");
	else if (sig == SIGTSTP)
		_print("\nProcess suspended\n");
}

/**
 * cleanup_tokens - frees tokens
 * @tokens: array
 * Return: void
 */
void cleanup_tokens(char **tokens)
{
	int x = 0;

	for (x = 0; tokens[x] != NULL; x++)
		free(tokens[x]);
	free(tokens);
}

/**
 * _strcpy - copies the string pointed to by src, to the buff
 * @dest: destination
 * @src: source
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int x = 0;

	for (x = 0; src[x] != '\0'; x++)
		dest[x] = src[x];
	dest[x] = '\0';
	return (dest);
}

/**
 * printenvronment - prints the environment
 * @_envir: environment variable
 * @_exit: integer
 * Return: 0 or 1
 */
int printenvronment(char **_envir, int *_exit)
{
	unsigned int x = 0;

	for (x = 0; _envir[x] != NULL; x++)
	{
		_print(_envir[x]);
		write(STDOUT_FILENO, "\n", 1);
	}
	*_exit = 0;
	return (0);
}
