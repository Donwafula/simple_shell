<<<<<<< HEAD
#include "shell.h"

/**
 * handlesigs - function that handles keyboard interrupt signals Ctrl+C and suspension signals Ctrl+Z
 * @sig: the signal
 */
void handlesigs(int sig)
{
  if (sig == SIGINT)
    {
      print("\nJDshell$ ");
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
  /*dest[x] = src[x];*/
  dest[x] = '\0'; /*added*/
  return (dest);
}
/**
 * printenvironment - prints the environment
 * @_envir: environment variable
 * @_exit: integer
 * Return: Always 0 in success. Otherwise 1.
 */
int printenvronment(char **_envir, int *_exit)
{
  unsigned int x;
  for (x = 0; _envir[x] != NULL; x++)
    {
      _print(_envir[x]);
      write(STDOUT_FILENO, "\n", 1);
    }
  *_exit = 0;
  return (0);
}
=======
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
	/*dest[x] = src[x];*/
	dest[x] = '\0';
	return (dest);
}

/**
 * printenvironment - prints the environment
 * @_envir: environment variable
 * @_exit: integer
 * Return: Always 0 in success. Otherwise 1.
 */
int printenvronment(char **_envir, int *_exit)
{
	unsigned int x;
    
    for (x = 0; _envir[x] != NULL; x++)
	{
		_print(_envir[x]);
		write(STDOUT_FILENO, "\n", 1);
	}

	*_exit = 0;
	return (0);
}
>>>>>>> fdc9a428e02f1c155a8e0483f2d150597193e271
