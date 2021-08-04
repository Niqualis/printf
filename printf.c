#include <stdarg.h>
#include "holberton.h"
#include <stddef.h>
/**
 * _printf - prints passed input
 * @format: how to print passed input
 *
 * Return: the number of characters printed
 */

/*
 * TODO:
 * To run with testMain: gcc testMain.c printf.c -o printfTest
 * testing: gcc printf.c _putchar.c holberton.h testMain.c -o mainTest
 *
 * just %
 * percent at end
 * garbage value from ...
 * mismatch between format and value
 *
 *
 */
int _printf(const char *format, ...)
{
int i, j, pos, count = 0; /*handling string function and int function*/
va_list ap; /* enables taking input from the ... */
which_t w[] = {
	{'c', print_char}, {'s', print_string}, {'%', print_percent},
	{'i', print_int}, {'d', print_int}, {'z', NULL}
};
va_start(ap, format);
if (format == NULL)
return (-1);
for (pos = 0; format[pos] != '\0'; pos++) /*loop through format, print chars*/
{
if (format[pos] == '%')/*checks for % in format string*/
{
pos++;
if (format[pos] == '\0')
return (-1);
for (i = 0; w[i].letter != 0; i++)
{
if (w[i].letter == format[pos])
{
j = (w[i].f)(ap);
if (j == -1)
return (-1);
else
count += j;
break;
}
if (w[i].letter == 'z')
return (-1);
}
}
else
{
count += _putchar(format[pos]);
}
}
va_end(ap);
return (count);
}

/**
 * findDepth - finds the length of an int
 * @number: int
 *
 * Return: length
 */

int findDepth(int number)
{
int depth = 1;
while (number / 10 != 0)
{
depth++;
number = number / 10;
}
return (depth);
}

/**
 * printDepth - prints an int given a depth
 * @number: to be printed
 * @depth: from findDepth
 *
 * Return: void
 */
int printDepth(int number, int depth)
{
int count = 0;
int localNumber = number;
int localDepth = depth;
int copy = number;
int depthCopy = depth;
if (localNumber < 0)
{
count += _putchar('-');
localNumber = localNumber * -1;
}
for (; localDepth > 0; localDepth--)
{
for (copy = localNumber, depthCopy = localDepth; depthCopy > 1; depthCopy--)
{
copy = copy / 10;
}
count += _putchar(copy % 10 + '0');
}
return (count);
}
