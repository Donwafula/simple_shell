#include "shell.h"

/**
 * error_extra - Print the error with extra information
 * @info: General information about the shell
 * @extra: Extra information
 **/
void error_extra(general_t *info, char *extra)
{
	char *m, *n, *a1, *a2;
	int size_n, size_m, size_extra;

	n = NULL;
	m = message_selector(*info);
	n = to_string(info->n_commands);

	size_n = _strlen(n);
	size_m = _strlen(info->argv[0]);
	size_extra = _strlen(extra);

	a1 = malloc(size_m + size_n + 3);
	a1 = _strcpy(a1, info->argv[0]);
	a1 = _strcat(a1, ": ");
	a1 = _strcat(a1, n);

	a2 = malloc(_strlen(m) + size_extra + 3);
	a2 = _strcpy(a2, m);
	a2 = _strcat(a2, ": ");
	a2 = _strcat(a2, extra);

	m = join_words(a1, info->command, a2, ": ");
	print_err(m);

	free(m);
	free(n);
	free(a1);
	free(a2);
}

/**
 * error - Print the error
 * @info: General info
 **/
void error(general_t *info)
{
	char *m;
	char *n;
	char *a;
	int size_number, size_message;

	n = NULL;
	m = message_selector(*info);
	n = to_string(info->n_commands);

	size_number = _strlen(n);
	size_message = _strlen(info->argv[0]);

	a = malloc(size_message + size_number + 3);

	a = _strcpy(a, info->argv[0]);
	a = _strcat(a, ": ");
	a = _strcat(a, n);

	m = join_words(a, info->command, m, ": ");
	print_err(m);

	free(m);
	free(n);
	free(a);
}
/**
 * sigintHandler - Handler for SIGINT
 * @sig_num: Unused parameter
 **/
void sigintHandler(int sig_num)
{
	(void) sig_num;

	signal(SIGINT, sigintHandler);
	print("\nJDshell$ ");
	fflush(stdout);
}

/**
 * prompt - Print the prompt
 * @info: Struct of general information
 **/
void prompt(general_t *info)
{
	if (info->mode == NON_INTERACTIVE)
		return;

	print("JDshell$ ");
}
