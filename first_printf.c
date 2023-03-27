#include "main.h"

/**
 * _printf - prints to stdout according to a format almost like printf
 * @format: pointer to the outputted value
 *
 * Return: Number of outputted characters excluding null bytes in string
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j = 0;

	va_start(args, format);
	while (format && format[i] != '\0')
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
					j += _puts(va_arg(args, char *));
					i += 2;
					break;
				case '%':
					j += _putchar('%');
					i += 2;
					break;
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
 * @c: right value
 *
 * Return: Always returns 0.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - helps to print a string
 * @s: The string to print to std
 *
 * Return: Always returns 0.
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
