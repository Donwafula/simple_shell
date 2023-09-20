#include "shell.h"

/**
 * _atoi - converts str to int
 * @s: str
 * Return: int
 */
int _atoi(char *s)
{
	size_t index = 0;
	int result = 0, sign = 1, digitEncountered = 0;

	while (s[index] == ' ')
		index++;
	if (s[index] == '-')
	{
		sign = -1;
		index++;
	}
	else if (s[index] == '+')
		index++;
	while (s[index] >= '0' && s[index] <= '9')
	{
		digitEncountered = 1;
		result = result * 10 + (s[index] - '0');
		index++;
	}
	if (!digitEncountered)
		return (0);
	return (sign * result);
}

/**
 * _getenv - Gets env
 * @name: env name
 * Return: env
 */
char *_getenv(const char *name)
{
	size_t i;

	if (name == NULL || environ == NULL)
		return (NULL);
	for (i = 0; environ[i] != NULL; i++)
	{
		char *env_var = environ[i];
		size_t len = _strlen(name);

		if (_strncmp(env_var, name, len) == 0 && env_var[len] == '=')
			return (_strdup(env_var + len + 1));
	}
	return (NULL);
}

/**
 * _strncmp - Compares at most the first n bytes of str1 and str2
 * @s1: str1
 * @s2: str2
 * @len: bytes
 * Return: len
 */
int _strncmp(const char *s1, const char *s2, size_t len)
{
	unsigned int p = 0;
	int d = 0;

	while (p < len)
	{
		if (s1[p] == s2[p])
		{
			p++;
			continue;
		}
		else
		{
			d = s1[p] - s2[p];
			break;
		}
		p++;
	}
	return (d);
}
