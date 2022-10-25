/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:50:52 by ubegona           #+#    #+#             */
/*   Updated: 2022/09/07 14:10:05 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_memmove(void *dst, const void *src, size_t len)
// {
// 	unsigned int	i;
// 	char			*c;

// 	i = 0;
// 	c = malloc(sizeof (char *) * len);
// 	while (i < len)
// 	{
// 		c[i] = ((char *)src)[i];
// 		i++;
// 	}
// 	i = 0;
// 	while (i < len)
// 	{
// 		((char *)dst)[i] = ((char *)dst)[i];
// 		i++;
// 	}
// 	return (dst);
// }

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;

	i = 0;
	if (dst <= src)
	{
		while (i < len && ((char *)dst || (char *)src))
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
	{
		while (i < len && ((char *)dst || (char *)src))
		{
			len--;
			((char *)dst)[len] = ((char *)src)[len];
		}
	}
	return (dst);
}
