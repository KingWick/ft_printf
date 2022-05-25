/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akram <akram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:32:27 by akdjebal          #+#    #+#             */
/*   Updated: 2022/05/26 01:09:45 by akram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
   return (1);
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

int    ft_putnbr_base_xX(unsigned long long nbr, char *base)
{
   int  count;
   
   count = 0;
   if (nbr >= 16)  
       count += ft_putnbr_base_xX(nbr / 16, base);
   count += ft_putchar(base[nbr % 16]);  
   
   return (count);
}  

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
	}
	return (i);
}

int   ft_putnbr_u(unsigned int nb)
{
   int count;

   count = 0;
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
      ft_putnbr_u(nb / 10);
      ft_putnbr_u(nb % 10);
   }
   return (count);
}

int ft_putnbr(int nb)
{
   int count;

   count = 0;
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
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
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
			if (str[i] == 'c')
				count += ft_putchar(va_arg(lst, int));
			if (str[i] == 'd')
				count += ft_putnbr(va_arg(lst, int));
			if (str[i] == 's')
				count += ft_putstr(va_arg(lst, char *));
			if (str[i] == 'p')
         {
            write(1,"0x", 2);
            count += 2;
				count += ft_putnbr_base_ptr(va_arg(lst, unsigned long long), "0123456789abcdef");
         }
			if (str[i] == 'u')
				count += ft_putnbr_u(va_arg(lst, unsigned int));
			if (str[i] == 'i')
				count += ft_putnbr(va_arg(lst, int)); 
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
   char a = 97;
   int  d = 93;
   int  c = 43;
   int  u = -95;
   int  i = -109;
   int  v = 75636;
   int  w = 2144;
   printf("%c--%d--%s--%p--%u--%i--%x--%X--%%", a, d, "Salut toi", &c, u, i, v, w);
   //printf("%d\n", ft_printf("salut\n"));
   //printf("%d\n", printf("salut\n"));
   // gerer le nill 
}