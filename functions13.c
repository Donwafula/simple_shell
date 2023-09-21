#include "shell.h"

/**
 * digits - Cout the numbe of digits of a number
 * @n: Number
 * Return: Digits
 **/
int digits(int n)
{
	int i;

	for (i = 0; n != 0; i++, n /= 10)
		;
	return (i);
}

/**
 * to_string - Conver @number to stri
 * @number: Number to conver
 * Return: Numbe
 **/
char *to_string(int number)
{
	int n_digits, i;
	char *_number;

	n_digits = digits(number);
	_number = malloc(n_digits * sizeof(char) + 2);
	if (number == 0)
	{
		_number[0] = '0';
		_number[1] = '\0';
		return (_number);
	}
	_number[n_digits] = '\0';
	for (i = n_digits - 1; number != 0; number /= 10, i--)
		_number[i] = (number % 10) + '0';

	return (_number);
}


/**
 * is_numerical - Check if
 * @n: Num
 * Return: return 1 else return 0
 */
int is_numerical(unsigned int n)
{
	return (n >= '0' && n <= '9');
}
