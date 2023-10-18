#include "main.h"
void print_buffer(char buffer[], int *buff_val);
/**
* _printf - Printf function
* @format: format.
* Return: Printed chars.
 */
int _printf(const char *format, ...)
{
int i, printed = 0, printed_chars = 0;
int flags, width, precision, size, buff_val = 0;
va_list arg_list;
char buffer[BUFF_SIZE];
if (format == NULL)
return (-1);
va_start(arg_list, format);
for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buffer[buff_val++] = format[i];
if (buff_val == BUFF_SIZE)
print_buffer(buffer, &buff_val);
/* write(1, &format[i], 1);*/
printed_chars++;
}
else
{
print_buffer(buffer, &buff_val);
flags = get_flags(format, &i);
width = get_width(format, &i, arg_list);
precision = get_precision(format, &i, arg_list);
size = get_size(format, &i);
++i;
printed = handle_print(format, &i, arg_list, buffer,
flags, width, precision, size);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}
print_buffer(buffer, &buff_val);
va_end(arg_list);
return (printed_chars);
}
/**
 * print_buffer - Prints the contents of buffer
 * @buffer: Array of chars
 * @buff_val: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_val)
{
if (*buff_val > 0)
write(1, &buffer[0], *buff_val);
*buff_val = 0;
}
