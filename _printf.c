#include "main.h"

/**
 * _printf - a function that produces
 * output according to a format
 * @format: pointer to the format
 * Return: number of characters
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i =  0;
	int num = 0;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'S')
				num = num + print_special_string(va_arg(args, char *));
			else
				num = num + print_char_string_or_percent(format[i], args);
		}
		i++;
	}
	va_end(args);
	return (num);
}

