#include "main.h"
void print_buffer(char buffer[], int *buff_val);
/**
* _printf - Printf function
* @format: format.
* Return: character
*/
int _printf(const char *format, ...)
{
int v, printed = 0, printed_chara = 0;
int flags, width, precision, size, buff_val = 0;
va_list num;
char buffer[BUFF_SIZE];
if (format == NULL)
return (-1);
va_start(num, format);
for (v = 0; format && format[v] != '\0'; i++)
{
if (format[v] != '%')
{
buffer[buff_val++] = format[v];
if (buff_val == BUFF_SIZE)
print_buffer(buffer, &buff_val);
/* write(1, &format[v], 1);*/
printed_chars++;
}
else
{
print_buffer(buffer, &buff_val);
flags = get_flags(format, &v);
width = get_width(format, &v, num);
precision = get_precision(format, &v, num);
size = get_size(format, &v);
++V;
printed = handle_print(format, &v, num, buffer, flags, width, precision, size);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}
print_buffer(buffer, &buff_val);
va_end(num);
return (printed_chara);
}
/**
* print_buffer - Prints the contents of the buffer if it exist
* @buffer: Array of chars
* @buff_val: Index at which to add next char, represents the length.
*/
void print_buffer(char buffer[], int *buff_val)
{
if (*buff_val > 0)
write(1, &buffer[0], *buff_val);
*buff_val = 0;
}
