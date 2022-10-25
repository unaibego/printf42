/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 10:39:08 by ubegona           #+#    #+#             */
/*   Updated: 2022/10/04 12:36:27 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	i;
	unsigned int	j;

	i = ft_strlen(s);
	j = 0;
	if (len <= i)
		p = malloc(len + 1);
	else
		p = malloc(i + 1);
	if (p == 0)
		return (NULL);
	while (start + j < i && j < len)
	{
		p[j] = s[start + j];
		j++;
	}
	p[j] = '\0';
	return (p);
}
