#include <unistd.h>
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * @n: count
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c, int n)
{
(write(1, &c, 1));
return (n + 1);
}