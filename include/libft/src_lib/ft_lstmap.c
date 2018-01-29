/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:25:52 by jgonthie          #+#    #+#             */
/*   Updated: 2016/12/08 15:42:22 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*new;
	t_list	*data;

	if (!lst || !(f))
		return (NULL);
	list = NULL;
	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	while (lst)
	{
		new = (*f)(lst);
		if (list)
		{
			data->next = new;
			data = data->next;
		}
		else
		{
			list = new;
			data = list;
		}
		lst = lst->next;
	}
	return (list);
}
