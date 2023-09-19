#include "shell.h"

/**
 * lacate - Finds command in path
 * @name: command
 * Return: path
*/
char *locate(const char *name)
{
	char *path = _getenv("PATH");
    char *token = NULL, *file_path = NULL;

    if (file_exists(name))
    {
        free(path);
        return _strdup(name);
    }

    token = strtok(path, ":");
    while (token != NULL)
    {
        file_path = join_paths('/', token, name);
        if (file_exists(file_path))
        {
            free(path);
            return file_path;
        }
        free(file_path);
        token = strtok(NULL, ":");
    }

    free(path);
    return NULL;
}

/**
 * join_paths - Joins two paths
 * @sep: separator
 * @path1: first path
 * @path2: second path
 * Return: joined path
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

	joined = malloc(sizeof(*joined) * (len + 1));
	
	i = 0;
	while (path1[k])
	{
		joined[i++] = path1[k++];
	}
	joined[i++] = sep;
	k = 0;
	while (path2[k])
	{
		joined[i++] = path2[k++];
	}
	joined[i] = '\0';
	return (joined);
}

/**
 * file_exists - Checks for executable file
 * @filepath: file path
 * Return: 1 if file exists, 0 otherwise
*/
int file_exists(const char *filepath)
{
	struct stat buffer;

	if (stat(filepath, &buffer) == 0)
	{
		return (1);
	}
	return (0);
}
