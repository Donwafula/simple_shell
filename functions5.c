#include "shell.h"

/**
 * _parsetokens - parses and tokenizes input
 * @input: input string
 * Return: array of tokens
*/
char **_parsetokens(const char *input)
{
	int token_count = 0;
	char *token;
	char **tokens = NULL;
	
	tokens = malloc((MAX_TOKENS + 1) * sizeof(**tokens));
	if (tokens == NULL)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}
	token = strtok((char *)input, " \n\t\r");
	while (token != NULL)
	{
		tokens[token_count] = _strdup(token);
		if (tokens[token_count] == NULL)
		{
			perror("handle_strdup failed");
			cleanup_tokens(tokens);
			exit(EXIT_FAILURE);
		}
		token_count++;
		token = strtok(NULL, " \n\t\r");
	}
	
	tokens[token_count] = NULL;
	
	return (tokens);
}

/**
 * _whitespace - checks if a string is whitespace
 * @str: string to check
 * Return: 1 if whitespace, 0 otherwise
*/
bool _whitespace(const char *str)
{
    size_t i;
	
	if (str == NULL)
	{
        return true;    }

    for (i = 0; str[i] != '\0'; i++)
	{
        if (str[i] != ' ' && str[i] != '\t')
		{
            return false;
        }
    }

    return true;
}

/**
 * _print - takes a pointer to a null-terminated character array as its argument
 * @str: input string
 * Return: void
 */
void _print(const char *str)
{
	size_t str_len;
	
	if (str == NULL)
	{
		write(STDOUT_FILENO, "(null)", 6);
		fflush(stdout);
		return;
	}
	str_len = _strlen(str);
	write(STDOUT_FILENO, str, str_len);
	fflush(stdout);
}
