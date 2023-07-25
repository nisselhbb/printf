#include "main.h"
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - function that produces output
 * according to a format
 * @format: a character string
 * Return: the number of character
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int width, buff_ind = 0;
	char buffer[BUFF_SIZE];
	va_list list;

	if (format == NULL)
		return (-1);
	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			if (format[i + 1] == '%')
			{
				buffer[buff_ind++] = '%';
				i++;
				if (buff_ind == BUFF_SIZE)
					print_buffer(buffer, &buff_ind);
				printed_chars++;
			}
			else if (format[i + 1] == 'c')
			{
				width = va_arg(list, int);
				printed = print_char(list, buffer, width);
				if (printed == -1)
					return (-1);
				print_char += printed;
				i++;
			}
			else if (format[i + 1] == 's')
			{
				width = va_arg(list, int);
				printed = print_string(list, buffer, width);
				if (printed == -1)
					return (-1);
				print_char += printed;
				i++;
			}
			else
			{
				buffer[buff_ind++] = format[i];
				if (buff_ind == BUFF_SIZE)
					print_buffer(buffer, &buff_ind);
				printed_chars++;
			}
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (printed_chars);
}
