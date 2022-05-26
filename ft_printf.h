/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:11:59 by akdjebal          #+#    #+#             */
/*   Updated: 2022/05/26 22:48:42 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int 	ft_putchar(char c);
int		ft_putstr(char *str);
int    	ft_putnbr_base_ptr(unsigned long long nbr, char *base);
int    	ft_putnbr_base_xX(unsigned int nbr, char *base);
int   	ft_putnbr_u(unsigned int nb);
int 	ft_putnbr(int nb);
int 	ft_printf(const char *str, ...);

#endif