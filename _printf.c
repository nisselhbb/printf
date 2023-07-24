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

	va_start(args, format);

	int num = 0;
	char specifier = *format;
	const char *string;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
	switch (specifier)
	{
		case 'c':
			_putchar(va_arg(args, int));
			num++;
			break;
		case 's':
			string = va_arg(args, const char*);
			while (*string != '\0')
			{
				_putchar(*string);
				num++;
				string++;
			}
			break;
		case '%':
			_putchar('%');
			num++;
			break;
		default:
			_putchar('%');
			_putchar(specifier);
			num = num + 2;
	}
		}
	format++;
	}
	va_end(args);
	return (num);
}
