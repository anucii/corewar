/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atropos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:55:28 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/13 12:25:00 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "judi.h"

/*
**	Called when timer reaches CYCLE_TO_DIE, checks the life.status of each process
**	NB : a killed process
**	- gets its malloc'd fields freed
**	- gets freed itself
**	- is pulled off the list in a way that does not destroys the list itself
*/

void	kill_proc(t_proc **ptr_proc)
{
	t_proc	*record;

	if (!(ptr_proc && *ptr_proc))
		return ;
	record = (*ptr_proc)->children;
	if ((*ptr->proc)->life.status)
		return ;
	free(*ptr_proc);
	*ptr_proc = record;
}

void	atropos(t_proc **tab)
{
	if (!tab)
		return ;
	foreach_proc(tab, &kill_proc);
}

/*
** Maintest
*/

int		main(void)
{
	t_proc *tab = 
}
