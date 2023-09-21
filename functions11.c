#include "shell.h"

/**
 * is_executable - Check if a filen
 * @filename: Filenam
 * Return: On success, PERMISSIONS
 */
int is_executable(char *filename)
{
	struct stat stats;

	if (stat(filename, &stats) == 0)
	{
		if (stats.st_mode & X_OK)
			return (PERMISSIONS);
		else
			return (NON_PERMISSIONS);
	}
	return (NON_FILE);
}

/**
 * _strlen - Return the leng
 * @msg: String to calculate length
 * Return: Length of the string
 **/
int _strlen(char *msg)
{
	int i;

	for (i = 0; msg[i] != '\0'; i++)
		;
	return (i);
}

/**
 * _strcat - Concatenates t
 * @dest: String concae
 * @src: Source string
 * Return: A string concatenate
 */
char *_strcat(char *dest, char *src)
{
	int l_dest, i;

	l_dest = _strlen(dest);
	for (i = 0; src[i] != '\0'; i++, l_dest++)
		dest[l_dest] = src[i];
	dest[l_dest] = '\0';
	return (dest);
}

/**
 * _strcpy - Copy a strin
 * @dest: Destiny
 * @src: Source for cop
 * Return: Return the value of dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
