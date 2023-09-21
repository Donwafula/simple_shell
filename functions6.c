#include "shell.h"

/**
 * bin_exit - Implementation of the exit builtin
 * Description: Free all the memory used and
 * exit with the last status_code
 * @info: Information about the shell
 * @arguments: Arguments received
 **/
void bin_exit(general_t *info, char **arguments)
{
	int status_c, status;

	status = _TRUE;
	if (arguments[1] != NULL)
	{
		status = number_controller(info, arguments[1]);
	}

	if (status == _FALSE)
	{
		return;
	}
	status_c = info->status_code;
	free_memory_pp((void **) arguments);
	free_memory_p((void *) info->buffer);
	free_memory_p((void *) info->environment);
	free_memory_p((void *) info);

	exit(status_c);
}

/**
 * replace_value - replace value
 * @info: info
 * @index: s
 * @string: str
 * Return: char
 */
char *replace_value(general_t *info, int *index, char *string)
{
	int x, new_s, old_s;
	char *value;

	x = *index;
	x++;

	value = replacement(info, index, string + x);
	if (value == NULL)
	{
		string = _strcpy(string, "");
		return (string);
	}

	old_s = _strlen(string);
	new_s = _strlen(value) + 1;

	string = _realloc(string, old_s, new_s);
	string = _strcpy(string, value);

	free_memory_p(value);
	*index = x;
	return (string);
}

/**
 * replace_env - env
 * @info: info
 * @environment: env
 * Return: cha
 */
char *replace_env(general_t *info, char *environment)
{
	char *env;

	(void) info;

	env = _getenv(environment);
	if (env != NULL)
		return (env);

	return (NULL);
}

/**
 * replacement - entry
 * @info: info
 * @index: in
 * @string: str
 * Return: char
 */

char *replacement(general_t *info, int *index, char *string)
{
	char *t;
	char symbol;

	(void) index;

	symbol = *string;
	if (symbol != '?' && symbol != '$')
	{
		t = replace_env(info, string);
		return (t);
	}

	t = (symbol == '$') ? to_string(info->pid) :
		to_string(info->status_code);

	return (t);
}
