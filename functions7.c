#include "shell.h"

/**
 * _cd_command - changes the current working directory
 * @tokens: array of toks
 * Return: void
 */
void _cd_command(char **tokens)
{
	char *new_dir = tokens[1], current_dir[PATH_MAX];
	static char prev_working_dir[PATH_MAX];

	if (new_dir == NULL)
	{
		new_dir = _getenv("HOME");
		if (new_dir == NULL)
		{
			perror("cd: HOME directory not found");
			return;
		}
	}
	if (_strcmp(new_dir, "-") == 0)
	{
		if (prev_working_dir[0] != '\0')
			new_dir = prev_working_dir;
		else
		{
			perror("cd: no previous directory");
			return;
		}
	}
	if (chdir(new_dir) == -1)
		perror("cd failed");
	else
	{
		if (getcwd(current_dir, sizeof(current_dir)) != NULL)
		{
			if (setenv("PWD", current_dir, 1) != 0)
				perror("setenv failed");
		}
		else
			perror("getcwd failed");
	}
}

/**
 * _exit_env - handles "exit" and "env" commands
 * @tokens: tokens
 * @env: env
 * @sh_exit: integer
 * Return: void
 */
Void _exit_env(char **tokens, char **env, int sh_exit)
{
	int status;

	sh_exit = 0;
	if (_strcmp(tokens[0], "exit") == 0)
	{
		if (tokens[1] != NULL)
		{
			if (tokens[2] != NULL)
			{
				_print("exit: too many arguments\n");
				return;
			}
			status = _atoi(tokens[1]);
			if (status != 0)
				sh_exit = status;
			else
			{
				_print("exit: numeric argument required\n");
				sh_exit = 2;
			}
		}
		free(tokens);
		exit(sh_exit);
	}
	else if (_strcmp(tokens[0], "env") == 0)
	{
		if (_strcmp(tokens[0], "env") == 0)
		{
			if (tokens[1] != NULL)
			{
				_print("env: too many arguments\n");
				return;
			}
			if (env != NULL)
			{
				if (printenvronment(env, &sh_exit) != 0)
					perror("env failed");
			}
		}
	}
}
