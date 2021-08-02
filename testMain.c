#include "holberton.h"
int main()
{
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
  _printf("testing%s123%c%i\n", "hello", 'a', 10 + -3);
}
