#include "shell.h"

/**
 * start_prompt - Loop re
 * @info: Struct of general in
 * Return: Buff NULL if EOF was found
 **/
void start_prompt(general_t *info)
{
	char *buff;
	char **arguments;
	char *path;

	signal(SIGINT, sigintHandler);
	while (1)
	{
		prompt(info);
		path = _getenv("PATH");
		is_current_path(path, info);
		info->environment = path;
		buff = read_prompt();
		if (buff == NULL)
		{
			print(info->mode == INTERACTIVE ? "exit\n" : "");
			free(path);
			break;
		}
		info->n_commands++;
		if (buff[0] != '\n')
		{
			arguments = split_words(buff, " \t\n");
			info->arguments = arguments;
			info->buffer = buff;
			analyze_patterns(info, arguments);
			analyze(arguments, info, buff);
			free_memory_pp((void *) arguments);
		}
		free_memory_p((void *) buff);
		free_memory_p((void *) path);
	}

}

/**
 * start - Handle the m
 * Description: Mode can be INTE
 * @info: Strucormation about the shell
 **/
void start(general_t *info)
{
	start_prompt(info);
}

/**
 * _putchar - Print a character
 * @c: Charact
 * Return: On 1 -1
 **/
int _putchar(char c)
{
	return (write(STDOUT, &c, 1));
}

/**
 * print - Print a message to STDOU
 * @msg: Messag
 * Return: On success number  On errror -1, and set the error
 */
int print(char *msg)
{
	return (print_to_fd(msg, STDOUT));
}
