#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 * print_string - prints an array of string characters
 * @str: the variable to print
 *
 */

int print_string(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}
