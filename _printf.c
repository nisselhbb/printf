#include "main.h"
/**
 * _printf - function that produces output
 * according to a format
 * @format: a character string
 * Return: the number of characters
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char *str = va_arg(args, char *);

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			case 'c':
				_putchar(va_arg(args, int));
				count++;
				break;
			case 's':
				while (*str != '\0')
				{
					_putchar(*str);
					str++;
					count++;
				}
				break;
			case '%':
				_putchar('%');
				count++;
				break;
			default:
				break;
		}
				else
				{
					_putchar(*format);
					count++;
				}
				format++;
	}
	va_end(args);
	return (count);
}

