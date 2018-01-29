/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foreach_proc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:40:47 by jdaufin           #+#    #+#             */
/*   Updated: 2018/01/25 16:56:37 by jdaufin          ###   ########.fr       */
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

	if (!(ptr_proc && *ptr_proc && func))
		return ;
	next = (*ptr_proc)->next;
	func(ptr_proc);
	if (next)
		apply(&next, func);
	else
		return ;
}

void		foreach_proc(t_proc **p, void (*func)(t_proc **))
{
	if (!(p && func))
		return ;
	apply(p, func);
}
