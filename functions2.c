#include "main.h"
/**
 * print_pointer - prints the value of a pointer
 * @type: list of arguments
 * @buffer: array of chars
 * @flags: if flags specified
 * @width: width field
 * @precision: if specified
 * @size: size specifier
 * Return: number of chars printed
 */
int print_pointer(va_list type, char buffer[], int flags, int width,
		int precision, int size)
{
	char c = 0, pad = ' ';
	int index = BUFF_SIZE - 1, length = 2, pad_start = 1;
	unsigned long  num_address;
	char map_to[] = "0123456789abcdef";
	void *address = va_args(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_address = (unsigned long)address;

	while (num_address > 0)
	{
		buffer[ind--] = map_to[num_address % 16];
		num_address /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';
	if (flags & F_PLUS)
		c = '+', length++;
	else if (flags & F_SPACE)
		c = ' ', length++;
	ind++;
	return (write_pointer(buffer, ind, length, width, flags, pad, c, pad_start));
}
