#include "shell.h"

/**
 * handlesigs - function that handles keyboard interrupt signals Ctrl+C
 *      and suspension signals Ctrl+Z
 * @sig: the signal
 */
void handlesigs(int sig)
{
    if (sig == SIGINT)
    {
        _print("\nJDshell$ ");
    }
    else if (sig == SIGTSTP)
    {
        _print("\nProcess suspended\n");
    }
}

/**
 * cleanup_tokens - frees tokens
 * @tokens: array of tokens
 * Return: void
*/
void cleanup_tokens(char **tokens)
{
	int x;
	
	for (x = 0; tokens[x] != NULL; x++)
	{
		free(tokens[x]);
	}
	free(tokens);
}

/**
 * _strcpy - copies the string pointed to by src, to the buffer
 * @dest: destination
 * @src: source
 * Return: the pointer to dest
 **/
char *_strcpy(char *dest, char *src)
{
	int x;

	for (x = 0; src[x] != '\0'; x++)
	{
		dest[x] = src[x];
	}
	dest[x] = src[x];
	return (dest);
}