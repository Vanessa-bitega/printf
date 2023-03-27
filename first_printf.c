#include "main.h"
/**
 * _printf - prints to stdout according to a format almost like printf
 * _putchar - helps to print %
 * _puts - helps  print the string
 * @format: pointer to the outputed value
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
			}
			continue;
		}
		j += _putchar(format[i]);
		i++;
	}
	va_end(args);
	return (j);
}

int _putchar(char c)
{
	return (write(1, &c, 1));
}
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
