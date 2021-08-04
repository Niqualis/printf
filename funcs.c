#include <stdarg.h>
#include "holberton.h"
#include <stddef.h>
#include <limits.h>
/**
 * print_char - prints a char
 * @ap: va_list
 *
 * Return: the number of characters printed
 */

int print_char(va_list ap)
{
return (_putchar(va_arg(ap, int)));
}

/**
 * print_string - prints a string
 * @ap: va_list
 *
 * Return: the number of characters printed
 */

int print_string(va_list ap)
{
char *s = (va_arg(ap, char *));
int i, count = 0;
if (s == NULL)
{
s = "(null)";
}
for (i = 0; s[i]; i++)
{
count += _putchar(s[i]);
}
return (count);
}

/**
 * print_percent - prints a percent
 * @ap: va_list
 *
 * Return: the number of characters printed
 */

int print_percent(va_list ap)
{
va_list p;
va_copy(p, ap);
_putchar('%');
return (1);
}

/**
 * print_int - prints an int
 * @ap: va_list
 *
 * Return: the number of characters printed
 */

int print_int(va_list ap)
{
int i, j; 
long int l;
l = va_arg(ap, long int);
if (l <= INT_MAX && l >= INT_MIN)
{
i = l;
j = findDepth(i);
return (printDepth(i, j));
}
else
{
return (-1);
}
}
