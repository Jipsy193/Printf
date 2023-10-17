#include "main.h"

/**
 * field_width - handles the field width for non-custom specifiers
 * @format: string to be printed
 * @i: List of arguments to be printed.
 * @arg_list: list of arguments.
 *
 * Return: width.
 */
int field_width(const char *format, int *i, va_list arg_list)
{
	int x;
	int width = 0;

	for (x = *i + 1; format[x] != '\0'; x++)
	{
		if (is_digit(format[x]))
		{
			width *= 10;
			width += format[x] - '0';
		}
		else if (format[x] == '*')
		{
			x++;
			width = va_arg(arg_list, int);
			break;
		}
		else
			break;
	}

	*i = x - 1;

	return (width);
}
