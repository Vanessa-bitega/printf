#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - write a fucntuction as it's format
 * @*format:
 * @...:
 * @format: var to use
 * Return:0
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	int count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				putchar('%');
				count++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(args, int);

				putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);

				for (; *s != '\0'; s++)
				{
					putchar(*s);
					count++;
				}
			}
		}
		else
		{
			putchar(*format);
			count++;
		} format++;
	} va_end(args);
	return (count);
}
