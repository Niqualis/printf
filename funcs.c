#include <stdarg.h>
#include "holberton.h"
#include <stddef.h>

int print_char(va_list ap)
{
return (_putchar(va_arg(ap, int)));
}

int print_string(va_list ap)
{
char *s = (va_arg(ap, char *));
int i, count = 0;
if (s == NULL)
{
return (-1);
}
for (i = 0; s[i]; i++)
{
count += _putchar(s[i]);
}
return (count);
}

int print_percent()
{
_putchar('%');
return (1);
}

int print_int(va_list ap)
{
int i, j;
i = va_arg(ap, int);
j = findDepth(i);
return (printDepth(i, j));
}
