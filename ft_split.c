/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:41:04 by ubegona           #+#    #+#             */
/*   Updated: 2022/10/04 12:31:16 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	contword(char const *s, char c)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != c)
			len++;
		while (s[i] != c && s[i])
			i++;
		if (s[i])
			i++;
	}
	return (len);
}

int	contletter(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != c && s[i])
	{
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char			**split;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	split = malloc(sizeof(char *) * (contword(s, c) + 1));
	if (split == 0)
		return (NULL);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		split[j] = ft_substr(s, i, contletter(&s[i], c));
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
		j++;
	}
	split[j] = NULL;
	return (split);
}

// int main ()
// {
// 	char			**split;
// 	unsigned int 	i;

// 	split = ft_split("hello!",' ');
// 	while (split[i])
// 	{
// 		printf("Erantzuna %s\n", split[i]);
// 		i++;
// 	}
// 	printf("  %s\n", split[i]);
// }
