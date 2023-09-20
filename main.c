#include "shell.h"

/**
 * main - Entry
 * @argc: count
 * @argv: vector
 * @envp: environment
 * Return: 0
 */
int main(int argc, char *argv[], char *envp[])
{
	char **tokens = NULL, *usr_input = NULL, **env = envp;
	siize_t _in;
	int sh_exit = 0;

	(void)argc, (void)argv;
	signal(SIGINT, handlesigs);
	signal(SIGTSTP, handlesigs);
	while (true)
	{
		_prompt();
		usr_input = _input();
		_in = _ctrld(usr_input, _strlen(usr_input), &sh_exit);
		if (_in == EXIT_STATUS_EOF)
			continue;
		tokens = _parsetokens(usr_input);
		if (tokens[0] != NULL)
		{
			_commands(tokens, env, &sh_exit);
		}
		cleanup_tokens(tokens);
	}
	free(usr_input);
	return (0);
}

/**
 * replacePID - Replace the process ID with the current process ID
 * @tokens: array of tokens
 * Return: void
 */
void replacePID(char **tokens)
{
	int rep = 0;

	for (rep = 0; tokens[rep] != NULL; rep++)
	{
		if (_strcmp(tokens[rep], "$$") == 0)
		{
			char p_IDStr[12];

			sprintf(p_IDStr, "%d", getpid());
			free(tokens[rep]);
			tokens[rep] = _strdup(p_IDStr);
		}
	}
}
