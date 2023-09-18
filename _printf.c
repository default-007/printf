#include <unistd.h>
#include <stdarg.h>
#include "main.h"

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
