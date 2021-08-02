#include "holberton.h"
#include <stdarg.h>
#include <stdio.h>

/**
* string_func - function to print strings
* @args: string passed into function
*
* Return: counter
*/

int string_func(va_list args)
{
int i;
char *s;

s = va_arg(args, char *);
if (s == NULL)
{
s = "(null)";
}
i = 0;
while (s[i])
{
_putchar(s[i]);
i++;
}
return (i);
}
