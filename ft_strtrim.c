/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:44:52 by ubegona           #+#    #+#             */
/*   Updated: 2022/09/22 09:10:12 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	g;
	char	*p;

	j = ft_strlen(s1) - 1;
	i = 0;
	g = 0;
	if (!s1[i])
	{
		p = (char *)malloc(1);
		p[0] = '\0';
		return (p);
	}	
	while (ft_strchr(set, s1[i]) && i < j)
		i++;
	while (ft_strchr(set, s1[j]) && j >= i)
		j--;
	p = (char *)malloc(j - i + 2);
	if (p == 0)
		return (NULL);
	while (i <= j)
		p[g++] = ((char *)s1)[i++];
	p[g] = '\0';
	return (p);
}

// int main()
// {
// 	printf("nirea |%s|\n", ft_strtrim("ABABABABA", "A"));
// }
