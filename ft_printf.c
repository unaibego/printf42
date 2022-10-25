/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:01:10 by ubegona           #+#    #+#             */
/*   Updated: 2022/10/11 11:03:09 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	changebase_punt(unsigned long long int a, unsigned int b, int *len)
{
	char	c;

	if (a >= b)
	{
		changebase_punt(a / b, b, len);
	}
	c = a % b + 48;
	if (c >= 58)
	{
		c = c + 39;
	}
	len[0]++;
	write(1, &c, 1);
}

void	changebase_uppercase(unsigned int a, unsigned int b, int *len)
{
	char	c;

	if (a >= b)
	{
		changebase_uppercase(a / b, b, len);
	}
	c = a % b + 48;
	if (c >= 58)
	{
		c = c + 7;
	}
	len[0]++;
	write(1, &c, 1);
}

void	ft_putnbr_pos(long int n, int *len)
{
	char	a;

	if (n < 0)
	{
		n = n * -1;
		n = 4294967296 - n;
	}
	if (n >= 10)
	{
		ft_putnbr_pos(n / 10, len);
	}
	a = (n % 10) + 48;
	len[0]++;
	write(1, &a, 1);
}

void	printf_conversion(char const *str, va_list variadica, int *len)
{
	if (*str == 'c')
		ft_putchar(va_arg(variadica, int), len);
	else if (*str == 's')
		ft_putstr(va_arg(variadica, char *), len);
	else if (*str == 'p')
	{
		ft_putstr("0x", len);
		changebase_punt(va_arg(variadica, unsigned long long int), 16, len);
	}
	else if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(variadica, int), len);
	else if (*str == 'u')
		ft_putnbr_pos(va_arg(variadica, int), len);
	else if (*str == 'x')
		changebase(va_arg(variadica, int), 16, len);
	else if (*str == 'X')
		changebase_uppercase(va_arg(variadica, int), 16, len);
	else if (*str == '%')
	{
		write(1, "%", 1);
		len[0]++;
	}
	va_end(variadica);
}

int	ft_printf(char const *str, ...)
{
	va_list	variadica;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start (variadica, str);
	while (str[i])
	{
		if (str[i] != '%')
			write(1, &str[i], 1);
		else
		{
			printf_conversion(&str[++i], variadica, &len);
			len = len - 1;
		}
		len++;
		i++;
	}
	return (len);
}

// int main()
// {
// 	char *p ;
// 	char a[100] = "kaixo mundua";
// 	int i;

// 	p = &a[0];
// 	i = 20;
// 	i = printf("orginality NULL %X %p %d\n", -4, LONG_MIN, i);
// 	i = ft_printf("nirea      NULL %X %p %d\n", -4, "hola", i);
// 	i = printf("orginality %s  %d\n", p, i);

// }
