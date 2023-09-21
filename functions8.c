#include "shell.h"

/**
 * main - Entry point of the shell
 * @argc: Number
 * @argv: Argus
 * Return: 0 on success and 1 on error
 **/
int main(int argc, char **argv)
{
	general_t *info;
	int status_c;

	info = malloc(sizeof(general_t));
	if (info == NULL)
	{
		perror(argv[0]);
		exit(1);
	}

	info->pid = getpid();
	info->status_code = 0;
	info->n_commands = 0;
	info->argc = argc;
	info->argv = argv;
	info->mode = isatty(STDIN) == INTERACTIVE;
	start(info);

	status_c = info->status_code;

	free(info);

	return (status_c);
}

/**
 * analyze_patterns - analyze
 * @info: info
 * @arguments: arg
 * Return: void
 */
void analyze_patterns(general_t *info, char **arguments)
{
	int x;

	for (x = 0; arguments[x] != NULL; x++)
		arguments[x] = pattern_handler(info, arguments[x]);
}

/**
 * pattern_handler - handler
 * @info: info
 * @string: string
 * Return: char
 */
char *pattern_handler(general_t *info, char *string)
{
	int x;

	for (x = 0; string[x] != '\0'; x++)
	{
		if (string[x] == '$' && string[x + 1] != '\0')
			string = replace_value(info, &x, string);
	}

	return (string);
}
