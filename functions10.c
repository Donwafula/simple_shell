#include "shell.h"

/**
 * print_err - Print a message to STDERR
 * @msg: Message to print
 * Return: Number of bytes printed
 **/
int print_err(char *msg)
{
	return (print_to_fd(msg, STDERR));
}

/**
 * _putchar_to_fd - Print a charac
 * @c: Character to print
 * @fd: Place to p
 * Return: On success 1
 */
int _putchar_to_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

/**
 * print_to_fd - Print a s
 * @msg: Strin ton the fd specified
 * @fd: File descriptor t
 * Return: On success numbers of bytes printed
 */
int print_to_fd(char *msg, int fd)
{
	int x;

	x = _strlen(msg);

	return (write(fd, msg, x));
}

/**
 * is_file - Check if is
 * Description: Lool for excute permiss
 * @file: File
 * Return: If is a file with the corre
 */
int is_file(char *file)
{
	int x, s;

	s = _strlen(file);
	for (x = 0; x < s; x++)
		if (file[x] == '/')
			return (is_executable(file));

	return (NON_FILE);
}
