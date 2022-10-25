/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:38:40 by ubegona           #+#    #+#             */
/*   Updated: 2022/10/03 12:51:56 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ds;
	t_list	*pr;

	if (!lst)
		return (NULL);
	ds = NULL;
	while (lst)
	{
		pr = ft_lstnew(f(lst -> content));
		if (!pr)
		{
			while (ds)
			{
				pr = ds -> next;
				del(ds -> content);
				free(ds);
				ds = pr;
			}
		}
		ft_lstadd_back(&ds, pr);
		lst = lst ->next;
	}
	return (ds);
}
