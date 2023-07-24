#ifndef PRINTF_H
#define PRINT_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int _putchar(char c);
int _printf(const char *format, ...);
int print_special_string(char *string);
int print_char_string_or_percent(char specifier, va_list args);
#endif
