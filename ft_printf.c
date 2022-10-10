/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:01:10 by ubegona           #+#    #+#             */
/*   Updated: 2022/10/10 13:51:37 by ubegona          ###   ########.fr       */
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
		// printf("que cojones le pasa a len %d\n", len[0]);
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

void	changebase_punt(long int a, unsigned int b, int *len)
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

void printf_conversion(char const *str, va_list variadica, int *len)
{
	if (*str == 'c')
		ft_putchar(va_arg(variadica, int), len);
	else if (*str == 's')
		ft_putstr(va_arg(variadica, char *), len);
	else if (*str == 'p')
	{
		ft_putstr("0x", len);
		changebase_punt(va_arg(variadica, uintptr_t), 16, len);
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
}

int	ft_printf(char const *str, ...)
{
	va_list	variadica;
	int	i;
	int len;

	i = 0;
	len = 0;
	va_start (variadica, str);
	while (str[i])
	{
		if (str[i] != '%')
			write(1, &str[i], 1);
		else
		{
			// printf("zelan doa len==|%d|\n", len);
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
