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
	void *address = va_arg(type, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_address = (unsigned long)address;

	while (num_address > 0)
	{
		buffer[index--] = map_to[num_address % 16];
		num_address /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';
	if (flags & F_PLUS)
		c = '+', length++;
	else if (flags & F_SPACE)
		c = ' ', length++;
	index++;
	return (write_pointer(buffer, index, length, width, flags, pad, c, pad_start));
}
/**
 * print_non_printable - prints ASCII values
 * in hexa of non printable chars
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags: if flags specified
 * @width: get width
 * @precision: if precision specified
 * @size: size specifier
 * Return: number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}
/**
 * print_reverse - prints string in reverse
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags: if flags specified
 * @width: get width
 * @precision: if precision specified
 * @size: size specifier
 * Return: number of chars printed
 */
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/**
 * print_rot13string - prints a string in rot13.
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags: if flags specified
 * @width: get width
 * @precision: if precision specified
 * @size: size specifier
 * Return: number of chars printed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
