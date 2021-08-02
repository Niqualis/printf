#include <stdarg.h>
#include "holberton.h"
#include <stdio.h>
/**
 * _printf - prints passed input
 * @format: how to print passed input
 *
 * Return: the number of characters printed
 */

/*TODO:
 * use case statement instead of if/else if
 * cut big function into smaller functions
 * implement handling for chars
 * implement handling for strings
 * implement handling for percents | DONE
 * implement handling for ints
 * implement handling for doubles
 * implement handling for unknown (%j or %q or something)
 * fringe cases
 * 	what if just "%"
 * 	what if format is blank
 * 	what if garbage value from ...
 * 	mismatch between format and passed value (%c and 3 or %i and "hey")
 *	string pointer == NULL
 * To run with testMain: gcc testMain.c printf.c _putchar.c -o printfTest 
 */
int _printf(const char *format, ...)
{
int i; /*handling string function and int function*/
int j;/*handling int function*/
char *s; /*hadling string function*/
int pos; /*position in format string*/
va_list ap; /*enables taking input from the ...*/
va_start(ap, format); 
	/*loops through format and prints each char*/
	for (pos = 0; format[pos] != '\0'; pos++)
	{
		/*checks for % in format string*/
		if (format[pos] == '%')
		{
		pos++;
			/*checks if value after % is c (it's a char) */
			if (format[pos] == 'c')
			{
                        _putchar(va_arg(ap, int));
			}
			/*checks if value after % is s (it's a string) */
			else if (format[pos] == 's')
			{
			    s = va_arg(ap, char *);
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
                        }
			/*checks if value after % is % (just print %) */
			else if (format[pos] == '%')
			{
                        _putchar('%');
			}
			/*checks if value after % is i (int) */
                        else if (format[pos] == 'i')
                        {
                        i = va_arg(ap, int);
			j = findDepth(i);
			printDepth(i, j);
			}
			/*checks if value after % is d (double) */
                        else if (format[pos] == 'd')
                        {
                        }
			/*there's a percent at the very end of format string */
			else if (format[pos] == '\0')
			{
			
			}
			/*there's a percent sign and not a recognized value after*/
			else
			{
			}

		}
		else /*if current char in format string is not % */
		{
		_putchar(format[pos]); /*print it like normal*/
		}
	}
va_end(ap);
}

int findDepth(int number)
{
	int depth = 1;
	while(number / 10 != 0)
	{
		depth++;
		number = number/10;
	}
	return depth;
}

void printDepth(int number, int depth)
{
int localNumber = number;
int localDepth = depth;
int copy = number;
int depthCopy = depth;

if(localNumber < 0)
{
_putchar('-');
localNumber = localNumber * -1;
}

for (;localDepth > 0; localDepth--)
{
for (copy = localNumber, depthCopy = localDepth; depthCopy > 1; depthCopy--)
{
copy = copy / 10;
}
_putchar(copy % 10 + '0');
}
}
