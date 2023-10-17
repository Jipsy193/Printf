#include "main.h"
/**
 * *
 *
 *
 *
 *
 *
 */
int _printf(const char *format, ...)
{
int char_count = 0;
va_list num;
va_start(num, format);
while (*format)
{
if (*format == '%')
{
format++;
if (*format == '\0') break;
if (*format == 'c')
{
int c = va_arg(num, int);
write(1, &c, 1);
char_count++;
}
else if (*format == 's')
{
const char *str = va_arg(num, const char *);
int str_len = strlen(str);
write(1, str, str_len);
char_count += str_len;
}
else if (*format == '%')
{
write(1, "%", 1);
char_count++;
}
else
{
write(1, "%", 1);
write(1, format, 1);
char_count += 2;
}
}
else
{
write(1, format, 1);
char_count++;
}
format++;
}
va_end(num);
return char_count;
}
