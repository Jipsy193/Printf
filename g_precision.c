#include "main.h"

/**
 * g_precision - handles the precision for specifier
 * @format: string to print arguments
 * @i: List of arguments that will be printed.
 * @arg_list: list of arguments.
 *
 * Return: Precision.
 */
int g_precision(const char *format, int *i, va_list arg_list)
{
	int x = *i + 1;
	int precision = -1;

	if (format[x] != '.')
		return (precision);

	precision = 0;

	for (x += 1; format[x] != '\0'; x++)
	{
		if (is_digit(format[x]))
		{
			precision *= 10;
			precision += format[x] - '0';
		}
		else if (format[x] == '*')
		{
			x++;
			precision = va_arg(arg_list, int);
			break;
		}
		else
			break;
	}

	*i = x - 1;

	return (precision);
}
