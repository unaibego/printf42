/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 08:45:23 by ubegona           #+#    #+#             */
/*   Updated: 2022/09/08 10:26:02 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	*p;
	unsigned int	i;

	p = malloc(size * count);
	if (p == 0)
		return (NULL);
	i = 0;
	ft_bzero(p, size * count);
	return ((void *)p);
}
