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
	char **tokens = malloc((MAX_TOKENS + 1) * sizeof(char *));

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