/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:32:27 by akdjebal          #+#    #+#             */
/*   Updated: 2022/05/22 16:08:49 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_put_adress(void const *p)
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
      adr = adr / 16;
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

void ft_hex(void *p)
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
      adr = adr / 16;
      i--;
   }
   //res[i] = base[(adr % 16)];
   while (i < 9)
   {
      ft_putchar(res[i]);
      i++;
   }
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, str++, 1);
	}
	return (0);
}

void    ft_putnbr_u(unsigned int nb)
{
        if (nb < 0)
        {
                ft_putchar('-');
                nb = -nb;
        }
        if (nb >= 0 && nb <= 9)
        {
                ft_putchar(nb + '0');
        }
        if (nb >= 10)
        {
                ft_putnbr_u(nb / 10);
                ft_putnbr_u(nb % 10);
        }
}


void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 0 && nb <= 9)
	{
		ft_putchar(nb + '0');
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

int ft_printf(const char *str, ...)
{
	int i;
	va_list lst;
	
	va_start (lst, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
				ft_putchar(va_arg(lst, int));
			if (str[i] == 'd')
				ft_putnbr(va_arg(lst, int));
			if (str[i] == 's')
				ft_putstr(va_arg(lst, char *));
			if (str[i] == 'p')
				ft_put_adress(va_arg(lst, void *));
			if (str[i] == 'u')
				ft_putnbr_u(va_arg(lst, unsigned int));
			if (str[i] == 'i')
				ft_putnbr(va_arg(lst, int)); 
			if (str[i] == 'x')
				ft_hex(va_arg(lst, void *));
		}
		else 
			 ft_putchar(str[i]);
		i++;
						
	}
	va_end (lst);
}

int main()
{
	int b = 7756555;
	
	ft_printf("%x\n",b);
	printf("%x\n",b);
}