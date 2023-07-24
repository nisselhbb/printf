#ifndef PRINTF_H
#define PRINTF_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int _putchar(char c);
int _printf(const char *format, ...);
int print_special_string(char *str);
int print_char_string_or_percent(char specifier, va_list args);
/**
 * print_char_string_or_percent - prints a character, string
 * or percent symbol
 * @specifier: conversion specifier
 * @args: printed arguments
 * Return: number of characters
 */
int print_char_string_or_percent(char specifier, va_list args)
{
	switch (specifier)
	{
		case 'c':
			return (print_char(args));
		case 's':
			return (print_string(args));
		case '%':
			return (_putchar('%'));
		default:
			return (_putchar('%') + _putchar(specifier));
	}
}
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
#endif
