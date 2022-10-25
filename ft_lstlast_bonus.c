/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:10:50 by ubegona           #+#    #+#             */
/*   Updated: 2022/09/28 12:16:23 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ds;

	ds = lst;
	if (!lst)
		return (NULL);
	while (ds -> next != NULL)
	{
		ds = ds ->next;
	}
	return (ds);
}
