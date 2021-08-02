#include <stdarg.h>
#include "holberton.h"
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
                        }
			/*checks if value after % is % (just print %) */
			else if (format[pos] == '%')
			{
                        _putchar('%');
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
