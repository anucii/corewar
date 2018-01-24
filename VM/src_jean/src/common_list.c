/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 04:24:24 by jdaufin           #+#    #+#             */
/*   Updated: 2018/01/24 17:26:44 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		clean_link(void *content, size_t size)
{
	if (!content)
		return ;
	free(content);
	content = NULL;
	size = 0;
}

static t_list	*seek_link(t_list **alst, void *pattern)
{
	t_list	*buf;
	t_list	*parent;
	
	if (!(alst && *alst))
		return (NULL);
	buf = *alst;
	parent = NULL;
	while (buf && (buf->content != pattern))
	{
		parent = buf;
		buf = buf->next;
	}
	return (parent);
	//return (buf);
}

/*
**	ft_lstpop() takes the adress of a link and ensures that the whole list
**	remains uninterrupted by its deletion
*/

static void		ft_lstpop(t_list **target)
{
	t_list	*record;

	if (target && *target && (*target)->next)
	{
		record = (*target)->next->next;
		ft_lstdelone(&((*target)->next), &clean_link);
		(*target)->next = record;
	}
}

/*
**	common_lst() provides a simple linked list of adresses, not a hard copy
**	of each of the processes; it is designed to fix the sequence of calls to
**	processes during the execution of orders
*/

t_list			*common_lst(t_req req, t_proc* proc)
{
	static t_list	*common_lst = NULL;
	t_list			*target;

	if (req == ADD)
		ft_lstadd(&common_lst, ft_lstnew(&proc, sizeof(t_proc **)));
	else if ((req == DEL) && common_lst && (target = seek_link(&common_lst, &proc)))
		ft_lstpop(&target);
	return (common_lst);
}
