#include "main.h"

/**

 * field_width - handles the field width for non-custom conversion specifier

 * @format: string to be printed

 * @i: List of arguments to be printed.

 * @arg_list: list of arguments.

 *

 * Return: width.

 */

int field_width(const char *format, int *i, va_list arg_list)

{

        int curr_i;

        int width = 0;


        for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)

        {

                if (is_digit(format[curr_i]))

                {

                        width *= 10;

                        width += format[curr_i] - '0';

                }

                else if (format[curr_i] == '*')

                {

                        curr_i++;

                        width = va_arg(arg_list, int);

                        break;

                }

                else

                        break;

        }


        *i = curr_i - 1;


        return (width);

}
