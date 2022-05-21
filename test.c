#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void my_put_padress (void const *p)
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
      putchar (res[i]);
      i++;
   }
}
 
int main (void)
{
   char const *q = "hello";
 
   printf ("%p\n", q);
   my_put_padress (q);
 
   return 0;
}