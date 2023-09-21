#include "shell.h"

/**
 * number_controller - Control the argum
 * @info: General inf about the shell
 * @number: Argument of the b
 * Return: If the actual argumen
 */
int number_controller(general_t *info, char *number)
{
	int _n;

	_n = _atoi(number);

	if (_n < 0 || contains_letter(number))
	{
		info->status_code = 2;
		info->error_code = _CODE_ILLEGAL_NUMBER;
		error_extra(info, number);
		return (_FALSE);
	}

	if (_n > 255)
		info->status_code = _n % 256;
	else
		info->status_code = _n;

	return (_TRUE);
}

/**
 * free_memory_pp - Free a double pointer
 * @ptr: Double pointer to free
 **/
void free_memory_pp(void **ptr)
{
	void **t;

	for (t = ptr; *t != NULL; t++)
		free_memory_p(*t);
	free_memory_p(ptr);
}

/**
 * free_memory_p - Free a pointer
 * @ptr: Pointer to free
 **/
void free_memory_p(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
	ptr = NULL;
}

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: Pointer to the memory previously allocated
 * @old_size: Size, in bytes, of the allocated space for ptr
 * @new_size: New size, in bytes of the new memory block
 * Return: Memory reallocated
 **/
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	char *x, *au;
	unsigned int a;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		x = malloc(new_size);
		if (x == NULL)
			return (NULL);

		return (x);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	x = malloc(new_size);
	if (x == NULL)
		return (NULL);
	au = ptr;
	for (a = 0; a < old_size; a++)
		x[a] = au[a];

	free(ptr);

	return (x);
}
