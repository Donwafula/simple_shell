#include "shell.h"

/**
 * custom_print - takes a pointer to a null-terminated
 *          character array as its argument
 * @str: input string
 * Return: void
*/
void handle_print(const char *str)
{
  size_t str_len = handle_strlen(str));

  write(STDOUT_FILENO, str, str_len);
}
