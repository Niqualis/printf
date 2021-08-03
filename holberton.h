#include <stdarg.h>
#ifndef HOLBERTON_H
#define HOLBERTON_H

typedef struct whichFunc{
	char letter;
	int (*f)(va_list);
} which_t;

int _putchar(char c);
int _printf(const char *format, ...);
int findDepth(int number);
int printDepth(int number, int depth);
int print_int(va_list);
int print_percent();
int print_char(va_list);
int print_string(va_list);
#endif
