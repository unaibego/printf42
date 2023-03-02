/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:01:10 by ubegona           #+#    #+#             */
/*   Updated: 2022/10/11 10:14:41 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *len)
{
	char	a;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		len[0] = len[0] + 11;
	}
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = n * -1;
			len[0]++;
		}
		if (n >= 10)
		{
			ft_putnbr(n / 10, len);
		}
		a = (n % 10) + 48;
		len[0]++;
		write(1, &a, 1);
	}
}

size_t	ft_strlen(const char *str)
{
	unsigned long	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	len[0]++;
}

void	ft_putstr(char *s, int *len)
{
	unsigned int	size;

	if (s)
	{
		size = ft_strlen(s);
		len[0] = len[0] + size;
		write(1, s, size);
	}
	else
	{
		len[0] = len[0] + 6;
		write(1, "(null)", 6);
	}
}

void	changebase(unsigned int a, unsigned int b, int *len)
{
	char	c;

	if (a >= b)
	{
		changebase(a / b, b, len);
	}
	c = a % b + 48;
	if (c >= 58)
	{
		c = c + 39;
	}
	len[0]++;
	write(1, &c, 1);
}
