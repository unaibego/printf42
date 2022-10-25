/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:18:39 by marvin            #+#    #+#             */
/*   Updated: 2022/10/03 11:49:25 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*primerelemento;

	primerelemento = (t_list *)malloc(sizeof(t_list));
	if (!primerelemento)
		return (NULL);
	primerelemento->content = content;
	primerelemento->next = NULL;
	return (primerelemento);
}
