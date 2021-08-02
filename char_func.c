#include "holberton.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * char_func - function that prints characters
 * @args: character passed into function
 *
 * Return: counter
 */

int char_func(va_list args)
{
  char c;

  c = va_arg(args, int);
  _putchar(c);
  return (1);
}
