#include "shell.h"

/**
 * _strlen - returns the lenght of a string
 * @s: pointer
 * Return: len
 * user command
 */
size_t _strlen(const char *s)
{
	size_t len = 0;

	if (s == NULL)
		return (0);
	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * _strdup - returns a pointer to a newly allocated space in mem
 * @command: command from user
 * Return: pointer
 */
char *_strdup(const char *command)
{
	char *str;
	size_t m = 0, n = 0;

	if (command == NULL)
		return (NULL);
	for (m = 0; command[m] != '\0'; m++)
		;
	str = (char *)  malloc((m + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	for (n = 0; n < m; n++)
		str[n] = command[n];
	str[m] = '\0';
	return (str);
}

/**
 * _strcmp - compares 2 strings
 * @s1: str1
 * @s2: str2
 * Return: diff
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return ((*s1 > *s2) ? 1 : -1);
}

/**
 * _strcat - concats 2 strs
 * @dest: pointer
 * @src: pointer
 * Return: 0
 */
char *_strcat(char *dest, const char *src)
{
	size_t x, len_dest = (dest != NULL) ? _strlen(dest) : 0;
	size_t len_src = (src != NULL) ? _strlen(src) : 0;
	char *result = NULL;

	if (dest == NULL || src == NULL)
		return (NULL);
	len_dest = _strlen(dest);
	len_src = _strlen(src);
	result = (char *)malloc(len_dest + len_src + 1);
	if (result == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	for (x = 0; x < len_dest; x++)
		result[x] = dest[x];
	for (x = 0; x < len_src; x++)
		result[len_dest + x] = src[x];
	result[len_dest + len_src] = '\0';
	return (result);
}
