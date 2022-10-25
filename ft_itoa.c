/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:16:29 by ubegona           #+#    #+#             */
/*   Updated: 2022/09/22 14:03:07 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count(int z)
{
	int	i;

	i = 0;
	if (z <= 0)
		i++;
	while (z != 0)
	{
		z = z / 10;
		i++;
	}
	return (i);
}

int	calcz(int z, char *p)
{
	if (z == -2147483648)
		z++;
	if (z < 0)
	{
		p[0] = '-';
		z = z * -1;
	}
	return (z);
}

char	*ft_itoa(int n)
{
	int		z;
	int		i;
	char	*p;

	z = n;
	i = count(z);
	p = malloc(sizeof(char) *(i + 1));
	if (p == 0)
		return (NULL);
	z = calcz(n, p);
	if (n == 0)
		p[0] = '0';
	p[i] = '\0';
	while (z != 0)
	{
		p[i - 1] = z % 10 + 48;
		z = z / 10;
		i--;
	}
	if (n == -2147483648)
		p[10] = '8';
	return (p);
}

// int main()
// {
// 	printf("nire itoa %s\n", ft_itoa(-2147483648));
// }
