/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:35:15 by akdjebal          #+#    #+#             */
/*   Updated: 2022/05/05 21:46:05 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	unsigned int		i;
	size_t				needle_len;
	unsigned int		tab;

	i = 0;
	needle_len = ft_strlen(n);
	if (0 == needle_len)
		return ((char *)h);
	while (h[i] && (needle_len + i) <= len)
	{
		tab = 0;
		while (h[tab + i] == n[tab])
		{
			if (tab == (needle_len - 1))
				return ((char *)h + i);
			tab++;
		}
		i++;
	}
	return (NULL);
}
