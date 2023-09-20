#include "shell.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * @envp: environment
 * Return: 0
*/
int main(int argc, char *argv[], char *envp[])
{
	char **tokens = NULL, *usr_input = NULL, **env = envp;
	size_t _in = 0;
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
			_commands(tokens, env, &sh_exit);
		cleanup_tokens(tokens);
	}
	free(usr_input);
	return (0);
}

