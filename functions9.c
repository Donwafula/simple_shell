#include "shell.h"

/**
 * _commands - executes commands
 * @command: array of tokens
 * @env: environment
 * @sh_exit: integer
 * Return: void
 */
void _commands(char **command, char **env, int *sh_exit)
{
	int x = 0, rep = 0;
	char **tokens, *command_str = "";

	for (x = 0; command[x] != NULL; x++)
	{
		if (x > 0)
			command_str = _strcat(command_str, " ");
		command_str = _strcat(command_str, command[x]);
	}
	tokens = _parsetokens(command_str);
	if (tokens[0] == NULL)
	{
		free(command_str);
		free(tokens);
		return;
	}
	for (rep = 0; tokens[rep] != NULL; rep++)
	{
		if (__strcmp(tokens[rep], "$") == 0)
			replacePID(tokens);
	}
	if (_strcmp(tokens[0], "cd") == 0)
		_cd_command(tokens);
	else if (_strcmp(tokens[0], "exit") == 0)
		_exit_env(tokens, env, *sh_exit);
	else if (_strcmp(tokens[0], "setenv") == 0)
		_setunsetenv(tokens);
	else if (_strcmp(tokens[0], "env") == 0)
		_exit_env(tokens, env, *sh_exit);
	else if (_strcmp(tokens[0], "unsetenv") == 0)
		_setunsetenv(tokens);
	else
		_external_exec(tokens, env);
	free(command_str);
}

/**
 * _ctrld - Handle input conditions including EOF and whitespace
 * @string: The input string
 * @read_result: The result of reading input
 * @exit_status: Pointer to the exit status variable
 * Return: 0 or EOF
 */
int _ctrld(char *string, ssize_t read_result, int *exit_status)
{
	int i = 0;

	if (read_result <= 0)
	{
		free(string);
		exit(*exit_status);
	}
	if (read_result == EOF)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(string);
		exit(*exit_status);
	}
	if (string == NULL)
		return (0);
	if (__strcmp(string, "\n") == 0)
	{
		*exit_status = 0;
		return (*exit_status);
	}
	while (string[i] != '\n')
	{
		if (string[i] != ' ' && string[i] != '\t')
			return (0);
		++i;
	}
	*exit_status = 0;
	return (*exit_status);
}
