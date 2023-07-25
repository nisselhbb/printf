#ifndef PRINTF_H
#define PRINTF_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "print_functions.c"
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
#define F_PLUS 1
#define F_MINUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
int _putchar(char c);
int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_ind);
int print_char(va_list args, char buffer[], int width);
int print_string(va_list args, char buffer[], int width);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int get_flags(const char *format, int *i);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int pad		d_start);


#endif
