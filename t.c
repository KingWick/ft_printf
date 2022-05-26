
#include <unistd.h>
#include <stdarg.h>

int ft_putchar(char c)
{
    write(1,&c,1);
    return (1);
}

int    ft_putnbr_base_xX(unsigned long long nbr, char *base)
{
   int  count;
   
   count = 0;
   if (nbr >= 16)  
       count += ft_putnbr_base_xX(nbr / 16, base);
   count += ft_putchar(base[nbr % 16]);  
   
   return (count);
}  
int ft_printf(const char *str, ...)
{
   int count;
	int i;
	va_list lst;
	
	va_start (lst, str);
	i = 0;
   count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'x')
				count += ft_putnbr_base_xX(va_arg(lst, unsigned long long), "0123456789abcdef");
         if (str[i] == 'X')
				count += ft_putnbr_base_xX(va_arg(lst, unsigned long long), "0123456789ABCDEF");
         if (str[i] == '%')
            count += ft_putchar('%');
		}
		else 
         count += ft_putchar(str[i]);
      i++;
						
	}
	va_end (lst);
   return (count);
}
int main()
{
    int d = 756398776;
    ft_printf("%x\n", d);
    ft_printf("%X", d); 
}