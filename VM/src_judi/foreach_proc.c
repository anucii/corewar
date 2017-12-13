/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foreach_proc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:40:47 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/13 12:25:08 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Applies the function passed by address to each element of the processes
**	array whose index is strictly inferior to max
*/

#include "judi.h"

static void	apply(t_proc **ptr_proc, void (*func)(t_proc **))
{
	if (!(ptr_proc && *ptr_proc && func))
		return ;
	if (!((*ptr_proc)->children))
		func(ptr_proc);
	else
		apply(&((*ptr->proc)->children), func);
}

void		foreach_proc(t_proc **tab, unsigned int max, void (*func)(t_proc **))
{
	unsigned int	i;

	if (!(tab && func))
		return ;
	i = 0;
	while (i < max)
	{
		apply(&tab[i], func);
		i++;
	}
}
