/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:50:13 by ubegona           #+#    #+#             */
/*   Updated: 2022/09/22 14:04:21 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	char			*p;
	char			*h;

	i = 0;
	h = (char *)s;
	if (n == 0)
		return (NULL);
	while ((unsigned char)h[i] != (unsigned char)c && i + 1 < n)
		i++;
	p = &((char *)s)[i];
	if ((unsigned char)h[i] == (unsigned char)c)
		return (p);
	else
		return (NULL);
}
