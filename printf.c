/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:01:10 by ubegona           #+#    #+#             */
/*   Updated: 2022/10/07 13:23:20 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putnbr(int n)
{
	char	a;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = n * -1;
		}
		if (n >= 10)
		{
			ft_putnbr(n / 10);
		}
		a = (n % 10) + 48;
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


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	unsigned int	len;

	len = ft_strlen(s);
	write(1, s, len);
}



void	changebase(int a, int b)
{
	char	c;

	if (a >= b)
	{
		changebase(a / b, b);
	}
	c = a % b + 48;
	if (c >= 58)
	{
		c = c + 39;
	}
	write(1, &c, 1);
}

void	changebase_uppercase(int a, int b)
{
	char	c;

	if (a >= b)
	{
		changebase(a / b, b);
	}
	c = a % b + 48;
	if (c >= 58)
	{
		c = c + 7;
	}
	write(1, &c, 1);
}

void	ft_putnbr_pos(long int n)
{
	char	a;

	if (n < 0)
	{
		n = n * -1;
		n = 4294967296 - n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	a = (n % 10) + 48;
	write(1, &a, 1);
}

void printf_conversion(char const *str, va_list variadica)
{
	if (*str == 'c')
		ft_putchar(va_arg(variadica, int));
	else if (*str == 's')
		ft_putstr(va_arg(variadica, char *));
	else if (*str == 'p')
	{
		ft_putstr("0x10");
		changebase(va_arg(variadica, size_t), 16);
	}
	else if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(variadica, int));
	else if (*str == 'u')
		ft_putnbr_pos(va_arg(variadica, int));
	else if (*str == 'x')
		changebase(va_arg(variadica, int), 16);
	else if (*str == 'X')
		changebase_uppercase(va_arg(variadica, int), 16);
	else if (*str == '%')
		write(1, "%", 1);
}

int	ft_printf(char const *str, ...)
{
	va_list	variadica;
	int	i = 0;

	va_start (variadica, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			printf_conversion(&str[i + 1], variadica);
		}
		i++;
	}
	return (i);
}

int main()
{
	char *p ;
	char a[100] = "sdkf67asdfd78";

	p = &a[0];
	printf("nirea %p\n", p);
	ft_printf("originality %p\n", p);
	
}
