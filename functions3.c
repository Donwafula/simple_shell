#include "shell.h"

/**
 * which - Find the directory needed
 *
 * @filename: Command received
 * @info: General info about the shell
 *
 * Return: pointer string with found path or NULL in failure.
 */
char *which(char *filename, general_t *info)
{
	char *path, *tmp_path, *tok;
	char *sl;
	int s;

	(void) info;

	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);

	tok = strtok(path, ":");
	s = _strlen(filename) + 2;
	sl = malloc(s * sizeof(char));
	sl = _strcpy(sl, "/");
	sl = _strcat(sl, filename);
	while (tok != NULL)
	{
		tmp_path = malloc(_strlen(tok) + s);
		tmp_path = _strcpy(tmp_path, tok);
		tmp_path = _strcat(tmp_path, sl);

		if (is_executable(tmp_path) == PERMISSIONS)
		{
			free(sl);
			free(path);
			return (tmp_path);
		}
		tok = strtok(NULL, ":");

		free(tmp_path);
	}
	free(path);
	free(sl);
	return (NULL);
}

/**
 * _getenv - Get a environment variable
 * @name: Environment variable to get
 * Return: On success value of @name
 * On error, NULL
 */
char *_getenv(const char *name)
{
	char **env;
	char *no, *token, *value;
	int s;

	s = _strlen((char *) name);

	for (env = environ; *env; ++env)
	{
		no = _strdup(*env);

		token = strtok(no, "=");
		if (token == NULL)
		{
			free(no);
			return (NULL);
		}
		if (_strlen(token) != s)
		{
			free(no);
			continue;
		}
		if (_strcmp((char *) name, no) == 0)
		{
			token = strtok(NULL, "=");
			value = _strdup(token);

			free(no);
			return (value);
		}

		free(no);
	}

	return (NULL);
}
/**
 * join_words - Join 3 words
 * Description: Result -> w1.sep
 * @word1: Word1 to join
 * @word2: Word2 to join
 * @word3: Word3 to join
 * @sep: Separator between the words
 * Return: Line composed by 3 parts followed b
 **/
char *join_words(char *word1, char *word2, char *word3,  const char *sep)
{
	char *a;
	int size_str1, size_str2, size_str3, size_sep;

	size_str1 = size_str2 = size_sep = 0;

	if (word1 != NULL)
		size_str1 = _strlen(word1);
	else
		word1 = "";

	if (word2 != NULL)
		size_str2 = _strlen(word2);
	else
		word2 = "";

	if (word3 != NULL)
		size_str3 = _strlen(word3);
	else
		word3 = "";

	if (sep != NULL)
		size_sep = _strlen((char *) sep);
	else
		sep = "";

	a = malloc(size_str1 + size_str2 + size_sep + size_str3 + size_sep + 2);
	if (a == NULL)
		return (NULL);

	a = _strcpy(a, word1);
	a = _strcat(a, (char *) sep);
	a = _strcat(a, word2);
	a = _strcat(a, (char *) sep);
	a = _strcat(a, word3);
	a = _strcat(a, "\n");
	return (a);
}
