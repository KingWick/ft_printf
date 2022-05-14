/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:32:27 by akdjebal          #+#    #+#             */
/*   Updated: 2022/05/13 18:48:12 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

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
			//if (str[i] == 'p')
			if (str[i] == 'u')
				ft_putnbr_u(va_arg(lst, unsigned int));
			
				
		}
		else 
			 ft_putchar(str[i]);
		i++;
						
	}
	va_end (lst);
}

int main()
{
	ft_printf("%u", 78);
}