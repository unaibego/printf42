/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:12:11 by ubegona           #+#    #+#             */
/*   Updated: 2022/10/11 10:13:54 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H
# define FT_PRINTF_H

# include "stdio.h"
# include "fcntl.h"
# include "unistd.h"
# include "stdlib.h"
# include "stdarg.h"

int		ft_printf(char const *str, ...);
void	ft_putnbr(int n, int *len);
size_t	ft_strlen(const char *str);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *s, int *len);
void	changebase(unsigned int a, unsigned int b, int *len);

#endif
