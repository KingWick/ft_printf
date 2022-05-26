#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_putchar(char c)
{
   write(1,&c,1);
   return 0;
}

int    ft_putnbr_base(unsigned long long nbr, char *base)
{
    int                    count;

    count = 0;
    if (nbr >= 16)
        count = count + ft_putnbr_base(nbr / 16, base);
    write(1, "0x", 2);  
   count = count + ft_putchar(base[nbr % 16]);
    return (count);
}
int main()
{
   int d = 4598886;
   ft_putnbr_base(d,"0123456789abcdef");
   //printf("\n%x", d);
}