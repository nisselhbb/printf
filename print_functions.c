#include "main.h"
/**
 * print_buffer - prints the contents of the buffer
 * is it exists
 * @buffer: array of chars
 * @buff_ind: pointer to index at which at which to add
 * the next char, representing the length
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind < 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
/**
 * print_char - prints a character to the buffer
 * @args: va_list of arguments
 * @buffer: array of chars
 * @width: minimun width for the printed
 * character
 * Return: number of printed characters
 */
int print_char(va_list args, char buffer[], int width)
{
	int printed = 0, pad;
	char c = va_arg(args, int);

	if (width < 0)
		width = 0;
	pad  = width - 1;

	while (pad > 0)
	{
		buffer[*buff_ind++] = ' ';
		if (*buff_ind == BUFF_SIZE)
			print_buffer(buffer, buff_ind);
		pad--;
		printed++;
	}
	buffer[*buff_ind] = c;
	if (*buff_ind == BUFF_SIZE)
		print_buffer(buffer, buff_ind);
	printed++;
	return (printed);
}
/**
 * print_string - prints a string to the buffer
 * @args: va_list of arguments
 * @buffer: array of chars
 * @width: minimun width for the printed string
 * Return: number of characters printed
 */
int print_string(va_list args, char buffer[], int width)
{
	int printed = 0, i;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	if (width < 0)
		width = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		buffer[*buff_ind++] = str[i];
	if (*buff_ind == BUFF_SIZE)
		print_buffer(buffer, buff_ind);
	printed++;
	}
	while (printed < width)
	{
		buffer[*buff_ind++] = ' ';
	if (buff_ind == BUFF_SIZE)
		print_buffer(buffer, buff_ind);
	printed++;
	}
	return (printed);
}
