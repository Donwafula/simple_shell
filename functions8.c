#include "shell.h"

/**
 * execute_command - locate and execute the command using PATH
 * @path: path to the command
 * @tokens: array of tokens
 * @env: environment
 * Return: void
*/
void execute_command(const char *path, char *tokens[], char **env)
{
	pid_t child_pid = 0;
	int status = 0, exit_status = 0;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (execve(path, tokens, env) == -1)
		{
			perror(tokens[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(child_pid, &status, 0) == -1)
		{
			perror("waitpid failed");
			exit(EXIT_FAILURE);
		}
		exit_status = WEXITSTATUS(status);

		if (exit_status == 1)
			_print("");
		_print("");
	}
}

/**
 * locate_and_execute - locate and execute the command using PATH.
 * @tokens: array of tokens
 * @env: environment
 * Return: void
 */
void locate_and_execute(char *tokens[], char **env)
{
	char *command_path = locate(tokens[0]);

	if (command_path != NULL)
	{
		execute_command(command_path, tokens, env);
		free(command_path);
	}
	else
		perror("Command not found\n");
}

/**
 * _external_exec - locate and execute the command using PATH
 * @tokens: array of tokens
 * @env: environment
 * Return: void
*/
void _external_exec(char *tokens[], char **env)
{
	if (file_exists(tokens[0]))
		execute_command(tokens[0], tokens, env);
	else
	{
		char *command_path = locate(tokens[0]);

		if (command_path != NULL)
			execute_command(command_path, tokens, env);
		else
			perror("Command not found\n");
	}
}
