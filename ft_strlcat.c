/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:33:37 by ubegona           #+#    #+#             */
/*   Updated: 2022/09/05 16:43:43 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(dst);
	if (dstsize > len)
	{
		while ((i < dstsize - len - 1) && (src[i]))
		{
			dst[len + i] = src[i];
			i++;
		}
		dst[len + i] = '\0';
	}
	if (len < dstsize)
	{
		return (ft_strlen(src) + len);
	}
	else
	{
		return (dstsize + ft_strlen(src));
	}
}
