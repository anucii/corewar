/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_unqueue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:07:27 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/08 14:04:24 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		get_depth(t_proc *p, int *depth)
{
	if (!p)
		return ;
	get_depth(p->next, depth);
	(*depth)++;
}

static t_proc	*unqueue(t_proc *p, int *depth, t_req req)
{
	static int	c = 0;

	if (!(p && depth && *depth))
		return (NULL);
	if (req == REINIT)
		c = 0;
	if (++c == *depth)
	{
		--(*depth);
		return (p);
	}
	return (unqueue(p->next, depth, NONE));
}

t_proc			*proc_unqueue(void)
{
	static int		depth = 0;
	static _Bool	first = 1;
	t_proc			*buf;

	buf = *proc_hdr(CHECK);
	if (first)
	{
		get_depth(buf, &depth);
		first = 0;
	}
	return (unqueue(buf, &depth, REINIT));
}
