#ifndef PRINTF_H
#define PRINTF_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "print_functions.c"
#define BUFF_SIZE 1024
int _putchar(char c);
int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_ind);
int print_char(va_list args, char buffer[], int width);
int print_string(va_list args, char buffer[], int width);
#endif
