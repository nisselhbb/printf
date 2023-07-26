#include "main.h"
/**
 * get_width - calculates width for printing
 * @format: string in which to print arguments
 * @i: list of arguments to be printed
 * @list: list of arguments
 * Return: width
 */
int get_width(const char *format, int *i, va_list list)
{
	int j;
	int width = 0;

	for (j = *i + 1; format[j] != '\0'; j++)
	{
		if (is_digit(format[j]))
		{
			width *= 10;
			width += format[j] - '0';
		}
		else if (format[j] == '*')
		{
			j++;
			width = va_arg(list, int);
				break;
		}
		else
			break;
	}
	*i = j - 1;
	return (width);
}
