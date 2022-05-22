#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_put_adress (void const *p)
{
   unsigned long adr;
   char const *base;
   char res[9];
   int i;
 
   adr = (unsigned long) p;
   base = "0123456789abcdef";
   i = 8;
   while ((adr / 16) > 0 || i >= 8)
   {
      res[i] = base[(adr % 16)];
      adr /= 16;
      i--;
   }
   res[i] = base[(adr % 16)];
   ft_putchar ('0');
   ft_putchar ('x');
   while (i < 9)
   {
      ft_putchar(res[i]);
      i++;
   }
}


int main (void)
{
	int a = 25;
	printf("%x", a);
    return 0;
}