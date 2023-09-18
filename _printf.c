#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - Prints character
 * @list: list of arguments
 * Return: Will return the amount of characters printed.
 */
int print_char(va_list list)
{
	_write_char(va_arg(list, int));
	return (1);
}

/**
 * print_string - Prints a string
 * @list: list of arguments
 * Return: Will return the amount of characters printed.
 */

int print_string(va_list list)
{
	int i;
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		_write_char(str[i]);
	return (i);
}

/**
 * _printf - Produces output according to a format
 * @format: The format of the string.
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	unsigned int j = 0, n = 0;

	va_start(ap, format);
	while (format[j] != '\0')
	{
		if (format[j] == '%')
		{
			switch (format[j + 1])
			{
				case 'c':
					_putchar(va_arg(ap, int));
					n++;
					break;
				case 's':
					n += print_string(va_arg(ap, char *));

					break;
				case '%':
					_putchar('%');
					n++;
					break;
			}

			j++;
		}
		else
		{
			_putchar(format[j]);
			n++;
		}
		j++;
	}
	va_end(ap);
	return (n);
}
