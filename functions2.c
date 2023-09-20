#include "shell.h"

/**
 * locate - Finds command in PATH
 * @name: command
 * Return: path
 * user commands
 */
char *locate(const char *name)
{
	char *path = _getenv("PATH"), *file_path = NULL;
	char *token = NULL, *result = NULL;

	if (file_exists(name))
	{
		free(path);
		return (_strdup(name));
	}
	token = strtok(path, ":");
	while (token != NULL)
	{
		file_path = join_paths('/', token, name);
		if (file_exists(file_path))
		{
			result = _strdup(file_path);
			free(file_path);
			break;
		}
		free(file_path);
		token = strtok(NULL, ":");
	}
	return (result);
}

/**
 * join_paths - Joins two paths
 * @sep: separator
 * @path1: path1
 * @path2: path2
 * Return: joined
 */
char *join_paths(const char sep, const char *path1, const char *path2)
{
	size_t i = 0, len = 0, k = 0;
	char *joined = NULL;

	while (path1[i++] != '\0')
		;
	len += i;
	i = 0;
	while (path2[i++] != '\0')
		;
	len += i;
	len += 1;
	joined = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (path1[k])
		joined[i++] = path1[k++];
	joined[i++] = sep;
	k = 0;
	while (path2[k])
		joined[i++] = path2[k++];
	joined[i] = '\0';
	return (joined);
}

/**
 * file_exists - Checks for executable file
 * @filepath: file path
 * Return: 1 or 0
 */
int file_exists(const char *filepath)
{
	struct stat buffer;

	if (stat(filepath, &buffer) == 0)
		return (1);
	return (0);
}
