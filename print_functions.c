#include "main.h"
/**
 * print_char - prints a character to
 * stdout
 * @args: printed arguments
 * Return: number of characters
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (_putchar (c));
}
/**
 * print_string - prints a string
 * @args: printed arguments
 * Return: number of characters
 */
int print_string(va_list args)
{
	int num = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		num = num + _putchar (*str);
		str++;
	}
	return (num);
}
