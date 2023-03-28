/**
 * _printf - Prints output according to a format
 * @format: Character string composed of zero or more directives
 *          See man 3 printf for more detail
 *
 * Return: Number of characters printed (excluding the null byte
 *         used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, len = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					len += _putchar(va_arg(args, int));
					break;
				case 's':
					len += _puts(va_arg(args, char *));
					break;
				case '%':
					len += _putchar('%');
					break;
				default:
					len += _putchar('%');
					len += _putchar(format[i]);
					break;
			}
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			len += _putchar('%');
			i++;
		}
		else
			len += _putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
