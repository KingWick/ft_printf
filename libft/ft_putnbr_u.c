/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:19:58 by akdjebal          #+#    #+#             */
/*   Updated: 2022/05/13 18:51:01 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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