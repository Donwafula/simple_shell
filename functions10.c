#include "shell.h"

/**
 * _unsetenv - Remove an environment variable
 * @name: The name of the environment variable to remove
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(const char *name)
{
	if (name == NULL)
		return (-1);
	if (unsetenv(name) != 0)
	{
		perror("unsetenv failed");
			return (-1);
	}
	return (0);
}

/**
 * _setenv - Initialize or modify an environment variable
 * @name: The name of the environment variable
 * @value: The value to set for the environment variable
 * @overwrite: If true, overwrite the variable if it exists
 * Return: 0 on success, -1 on failure
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	if (name == NULL || value == NULL)
		return (-1);
	if (overwrite || getenv(name) == NULL)
	{
		if (setenv(name, value, 1) != 0)
		{
			perror("setenv failed");
			return (-1);
		}
	}
	return (0);
}
