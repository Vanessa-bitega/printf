#include "main.h"
/**
 * _printf - prints to stdout according to a format almost like prinf
 * @format: pointer to the outputed value
 *
 * Return: Number of outputd characters exluding null bytes in string
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j = 0;

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
					j += _putchar(va_arg(args, int));
					i += 2;
					break;
				case 's':
					j += _puts(va_arg(args, char*));
					i += 2;
					break;
				case '%':
					j += _putchar('%');

					i += 2;
					break;
				default:
					va_end(args);
					return (-1);
			}
			continue;
		}
		j += _putchar(format[i]);
		i++;
	}
	va_end(args);
	return (j);
}
/**
 * _putchar - helps to print %
 * This function prints a percent sign to stdout.
 * @c: the value to check
 *
 * Return: i
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - helps to print a string
 * @s: the outputed value
 *
 * Return: a string
 */
int _puts(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
	return (i);
}
