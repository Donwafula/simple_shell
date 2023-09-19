#include "shell.h"

/**
 * _atoi - Converts a string to an integer
 * @s: The string to be converted
 * Return: The integer
*/
int _atoi(char *s)
{
    size_t index = 0;
    int result = 0;
    int sign = 1;
    int digitEncountered = 0;

    while (s[index] == ' ')
    {
        index++;
    }
    if (s[index] == '-')
    {
        sign = -1;
        index++;
    }
    else if (s[index] == '+')
    {
        index++;
    }
    while (s[index] >= '0' && s[index] <= '9')
    {
        digitEncountered = 1;
        result = result * 10 + (s[index] - '0');
        index++;
    }
    if (!digitEncountered)
        return 0;

    return sign * result;
}

/**
  * _getenv - Gets an environment variable
  * @name: The variable to find in the system environment
  *
  * Return: The content of the environment variable
  */
char *_getenv(const char *name)
{
	size_t i = 0, k = 0;
	char *varenv = NULL;

	while(environ[i] != NULL)
	{
		varenv = environ[i];
		k = 0;
		while (varenv[k] == name[k] && varenv[k] != '=' && varenv[k] && name[k])
		{
			k++;
		}
		if (name[k] == '\0' && varenv[k] == '=')
		{
			return (_strdup(varenv));
		}
		i++;
	}
	return (NULL);
}

/**
  * _strncmp - Compares at most the first n bytes of str1 and str2
  * @s1: The first string
  * @s2: The second string
  * @len: The limit bytes of comparison
  *
  * Return: int value
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
