/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:35:58 by jgonthie          #+#    #+#             */
/*   Updated: 2017/04/11 18:11:56 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
		new->next = NULL;
	}
	else
	{
		if (content && content_size)
		{
			if (!(new->content = malloc(content_size)))
			{
				free(new);
				return (NULL);
			}
			ft_memcpy(new->content, content, content_size);
			new->content_size = content_size;
			new->next = NULL;
		}
	}
	return (new);
}
