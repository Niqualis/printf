#include "holberton.h"
int print_binary(va_list ap)
{
unsigned int i = va_arg(ap, unsigned int);
int length;/*length of binary number*/
int num;/*biggest number that can go into int i*/
int count = 0;
/*makes num largest divisble number to i and length the length of the decimal*/
for(length = 0, num = 1; i / num != 0; num = num * 2, length++)
{
}
num = num/2;
for(;num != 0; num = num/2)
{
if (i/num == 1)
{
count += _putchar('1');
i = i%num;
}
else    
count += _putchar('0');
}
return (count);
}
