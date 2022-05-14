/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdjebal <akdjebal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:20:31 by akdjebal          #+#    #+#             */
/*   Updated: 2022/05/05 21:09:16 by akdjebal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int searchfirstcharac)
{
	while (*s != '\0' && *s != searchfirstcharac)
		s++;
	if (*s == searchfirstcharac)
		return ((char *)s);
	return (0);
}
