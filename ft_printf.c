/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:32:27 by akdjebal          #+#    #+#             */
/*   Updated: 2022/05/26 22:48:28 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(char c)
{
	write(1, &c, 1);
   return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
   if (!str)
   {
      write(1, "(null)", 6);
      return (6);
   }
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
      i++;
	}
	return (i);
}

int    ft_putnbr_base_ptr(unsigned long long nbr, char *base)
{
   int  count;

   	count = 0;
   	if (nbr >= 16)
   		count += ft_putnbr_base_ptr(nbr / 16, base);
	count += ft_putchar(base[nbr % 16]);
   	return (count);
}

int    ft_putnbr_base_xX(unsigned int nbr, char *base)
{
   int  count;
   
   count = 0;
   if (nbr >= 16)  
      count += ft_putnbr_base_xX(nbr / 16, base);
   count += ft_putchar(base[nbr % 16]);  
   return (count);
}  

int   ft_putnbr_u(unsigned int nb)
{
   int count;

   count = 0;
   if (nb <= 9)
   {
      count += ft_putchar(nb + '0');
   }
   else if (nb >= 10)
   {
      count += ft_putnbr_u(nb / 10);
      count += ft_putnbr_u(nb % 10);
   }
   return (count);
}

int ft_putnbr(int nb)
{
   int count;

   count = 0;
   if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 0 && nb <= 9)
	{
		count += ft_putchar(nb + '0');
	}
	if (nb >= 10)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
   return (count);
}

int ft_printf(const char *str, ...)
{
	int count;
	int i;
	va_list lst;
	unsigned long long	ptr;
		
	va_start (lst, str);
	i = 0;
   count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
				count += ft_putchar(va_arg(lst, int));
			if (str[i] == 'd')
				count += ft_putnbr(va_arg(lst, int));
			if (str[i] == 's')
				count += ft_putstr(va_arg(lst, char *));
			if (str[i] == 'p')
			{
				ptr = va_arg(lst, unsigned long long);
				if (!ptr)
					 count += write(1, "(nil)", 5);
				else
				{
					count += write(1,"0x", 2);
					count += ft_putnbr_base_ptr(ptr, "0123456789abcdef");
				}
			}
			if (str[i] == 'u')
				count += ft_putnbr_u(va_arg(lst, unsigned int));
			if (str[i] == 'i')
				count += ft_putnbr(va_arg(lst, int)); 
			if (str[i] == 'x')
				count += ft_putnbr_base_xX(va_arg(lst, unsigned int), "0123456789abcdef");
            if (str[i] == 'X')
				count += ft_putnbr_base_xX(va_arg(lst, unsigned int), "0123456789ABCDEF");
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
//    char c = 'a';
   char *str;
   str = malloc(sizeof(char) * 5);
	free(str);
	(void)str;
//   ft_printf("%c--%d--%s--%p--", c, d, "salut toi", &str);

	//printf("\n%p\n", NULL);
  	//ft_printf("%p\n", NULL);
//    printf("count %d\n", printf("%c--%d--%s--%p\n", c, d, str, &str));
//    printf("count %d\n", ft_printf("%c--%d--%s--%p\n", c, d, str, &str));
   // gerer le nill 
}