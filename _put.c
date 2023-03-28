#include <unistd.h>

/**
 * _puts - writes a string to stdout
 * @str: the string to write
 *
 * Return: the number of characters written
 */
int _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0')
		i++;
	return (write(1, str, i));
}
