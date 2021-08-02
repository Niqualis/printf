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
 * use case statement instead of if/else if
 * cut big function into smaller functions
 * implement handling for chars
 * implement handling for strings
 * implement handling for percents | DONE
 * implement handling for ints
 * implement handling for doubles
 * implement handling for unknown (%j or %q or something)
 * fringe cases
 * ________what if just "%"
 * ________what if format is blank
 * ________what if garbage value from ...
 * ________mismatch between format and passed value (%c and 3 or %i and "hey")
 * ________string pointer == NULL
 * To run with testMain: gcc testMain.c printf.c -o printfTest
 * printNumbers +1 when printing a negative int
 */
int _printf(const char *format, ...)
{
int i, j, pos, printNumber = 0; /*handling string function and int function*/
char *s; /* hadling string function */
va_list ap; /* enables taking input from the ... */
va_start(ap, format);
for (pos = 0; format[pos] != '\0'; pos++) /*loop through format, print chars*/
{
if (format[pos] == '%')/*checks for % in format string*/
{
pos++;
switch (format[pos])
{
	case 'c':/*checks if value after % is c (it's a char) */
printNumber = _putchar(va_arg(ap, int), printNumber);
break;
	case 's':/*checks if value after % is s (it's a string) */
s = va_arg(ap, char *);
printString(s);
printNumber++;
break;
	case '%':/*checks if value after % is % (just print %) */
printNumber = _putchar('%', printNumber);
break;
	case 'i':/*checks if value after % is i (int) */
	case 'd':
i = va_arg(ap, int);
j = findDepth(i);
printDepth(i, j);
break;
	case 0:/*there's a percent sign and not a recognized value after*/
break;
}
}
else/*if current char in format string is not % */
{
printNumber = _putchar(format[pos], printNumber); /*print it like normal*/
}
}
va_end(ap);
return (printNumber);
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
void printDepth(int number, int depth)
{
int localNumber = number;
int localDepth = depth;
int copy = number;
int depthCopy = depth;

if (localNumber < 0)
{
_putchar('-', 0);
localNumber = localNumber * -1;
}

for (; localDepth > 0; localDepth--)
{
for (copy = localNumber, depthCopy = localDepth; depthCopy > 1; depthCopy--)
{
copy = copy / 10;
}
_putchar(copy % 10 + '0', 0);
}
}

/**
 * printString - prints passed input
 * @s: string to be printed
 *
 * Return: void
 */

void printString(char *s)
{
int i = 0;
if (s == NULL)
{
s = "(null)";
}
while (s[i])
{
_putchar(s[i], 0);
i++;
}
}
