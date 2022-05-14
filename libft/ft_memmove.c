/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 20:40:11 by akdjebal          #+#    #+#             */
/*   Updated: 2022/05/05 20:22:28 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*destination;
	unsigned char	*source;

	if (dest == NULL && src == NULL)
		return (0);
	if (n == 0)
		return (dest);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		destination = (unsigned char *)dest;
		source = (unsigned char *)src;
		i = n;
		while (i-- != 0)
		{
			destination[i] = source[i];
		}
	}
	return (dest);
}
