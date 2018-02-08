/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foreach_proc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:40:47 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/08 13:52:15 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Applies the function passed by address to each element of the processes
**	list;
**	the 'next' variable is here to secure the case where the pointee is deleted
**	by the called function (e.g kill())
*/

#include "vm.h"

static void	apply(t_proc **ptr_proc, void (*func)(t_proc **))
{
	t_proc	*next;
	t_proc	*tmp;

	if (!(ptr_proc && *ptr_proc && func))
		return ;
	next = (*ptr_proc)->next;
	tmp = (*ptr_proc);
	while (tmp != NULL)
	{
		func(&tmp);
		if (tmp != next)
		{
			tmp = next;
			if (next)
				next = next->next;
		}
		else
			next = tmp->next;
	}
}

void		foreach_proc(t_proc **p, void (*func)(t_proc **))
{
	if (!(p && func))
		return ;
	apply(p, func);
}
