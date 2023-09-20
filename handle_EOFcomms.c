#include "shell.h"

/**
 * _ctrld - Handle input conditions including EOF and whitespace
 * @string: The input string.
 * @read_result: The result of reading input.
 * @exit_status: Pointer to the exit status variable.
 * Return: 0 for normal input, EXIT_STATUS_EOF for EOF
 */
int _ctrld(char *string, ssize_t read_result, int *exit_status)
{
    int i = 0;
    
    if (read_result == EOF)
    {
        if (isatty(STDIN_FILENO))
        {
            write(STDOUT_FILENO, "\n", 1);
        }
        free(string);
        exit(*exit_status);
    }
    if (_strcmp(string, "\n") == 0)
    {
        *exit_status = 0;
        return EXIT_STATUS_EOF;
    } 
    while (string[i] != '\n')
    {
        if (string[i] != ' ' && string[i] != '\t')
        {
            return 0;
        }
        ++i;
    }
    *exit_status = 0;
    return EXIT_STATUS_EOF;
}