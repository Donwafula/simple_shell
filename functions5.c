#include "shell.h"

/**
 * message_selector - Select the message that match with the error_code
 * @info: General information about the shell
 * Return: Error message
 **/
char *message_selector(general_t info)
{
	int x, n_options;
	error_t messages[] = {
		{_ENOENT, _CODE_ENOENT},
		{_EACCES, _CODE_EACCES},
		{_CMD_NOT_EXISTS, _CODE_CMD_NOT_EXISTS},
		{_ILLEGAL_NUMBER, _CODE_ILLEGAL_NUMBER}
	};

	n_options = sizeof(messages) / sizeof(messages[0]);
	for (x = 0; x < n_options; x++)
		if (info.error_code == messages[x].code)
			return (messages[x].message);

	return ("");
}

/**
 * execute - Execute a command in other process
 * @command: Command to execute
 * @arguments: Arguments of the @command
 * @info: General info about the shell
 * @buff: Line readed
 **/
void execute(char *command, char **arguments, general_t *info, char *buff)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		execve(command, arguments, environ);
		perror("./sh");

		free_memory_pp((void *) arguments);

		if (info->value_path != NULL)
		{
			free(info->value_path);
			info->value_path = NULL;
		}

		free(info);
		free(buff);
		exit(1);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			info->status_code = WEXITSTATUS(status);
	}
}

/**
 * current_directory - Execute the command if the order require
 * @cmd: Command to execute
 * @arguments: Arguments of the @cmd
 * @buff: Line readed
 * @info: General info about the shell
 * Return: Status of the operations
 **/
int current_directory(char *cmd, char **argus, char *buff, general_t *info)
{

	if (info->is_current_path == _FALSE)
	{
		return (_FALSE);
	}
	if (is_executable(cmd) == PERMISSIONS)
	{
		execute(cmd, argus, info, buff);
		return (_TRUE);
	}
	return (_FALSE);
}

/**
 * read_prompt - Read lines in the prompt
 * Return: Buffer readed or NULL if EOF was found
 **/
char *read_prompt()
{
	char *buffer;
	int res;
	size_t size;

	buffer = NULL;

	res = getline(&buffer, &size, stdin);

	if (res == EOF)
	{
		free_memory_p((void *) buffer);
		return (NULL);
	}

	return (buffer);
}
