/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:06:18 by akdjebal          #+#    #+#             */
/*   Updated: 2022/05/05 21:19:58 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	lenght;
	unsigned int	i;
	char			*result;

	i = -1;
	if (!s || !f)
		return (NULL);
	lenght = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (lenght + 1));
	if (!result)
		return (NULL);
	result[lenght] = 0;
	while (++i < lenght)
		result[i] = f(i, *(s + i));
	return (result);
}
