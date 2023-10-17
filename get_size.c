#include "main.h"

/**
 * get_size - Calculates the size of an argument
 * @format: string to be formatted
 * @i: List of arguments to be printed.
 *
 * Return: Size.
 */
int get_size(const char *format, int *i)
{
	int x = *i + 1;
	int size = 0;

	if (format[x] == 'l')
		size = S_LONG;
	else if (format[x] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = x - 1;
	else
		*i = x;

	return (size);
}
