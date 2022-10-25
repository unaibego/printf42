/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:20:20 by ubegona           #+#    #+#             */
/*   Updated: 2022/10/03 10:26:53 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ds;
	t_list	*pr;

	ds = *lst;
	if (!lst)
		return ;
	while (ds != NULL)
	{
		pr = ds ->next;
		ft_lstdelone(ds, del);
		ds = pr;
	}
	*lst = NULL;
}
