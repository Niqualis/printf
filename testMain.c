#include "holberton.h"
int main()
{
  int n; 
/*test case: 
 * prints "testing" 
 * %s is a false specifier right now so it doesn't print and skips over 
 * prints 123
 * prints the char a (because theres a %c for char) 
 * follows with a new line.
 *
 * Feel free to change this test to suit your needs. 
 * -Isaac
 * */
n =  _printf("testing%s123%c\n", "hello", 'a');
 _printf("%i", n);
}

