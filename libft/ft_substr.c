/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 10:39:15 by akdjebal          #+#    #+#             */
/*   Updated: 2022/05/05 21:25:51 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str2;

	if (!str || !*str || start > ((unsigned int)ft_strlen(str) + 1) || len == 0)
		return (ft_calloc(sizeof(char), 1));
	str2 = (char *)malloc(sizeof(char) * len + 1);
	if (str2 == NULL)
		return (NULL);
	i = (size_t)start;
	j = 0;
	while (str[i] && i < (len + start))
	{
		str2[j] = str[i];
		i++;
		j++;
	}
	if (str2)
		str2[j] = '\0';
	return (str2);
}
