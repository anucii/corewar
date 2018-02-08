/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atropos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:55:28 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/08 12:10:14 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Called when timer reaches CYCLE_TO_DIE, checks the life.status of each
**	process
**	NB : a killed process
**	- gets its malloc'd fields freed
**	- gets freed itself
**	- is pulled off the list in a way that does not destroys the list itself
*/

void	kill_proc(t_proc **ptr_proc)
{
	t_info	*info;

	if (!(ptr_proc && *ptr_proc))
		return ;
	if ((global_timer(CHECK) - (*ptr_proc)->life.last) < deadline(CHECK))
		return ;
	info = get_info(NULL);
	if (info->opt[3] && info->opt[4] && !info->opt[0])
		ft_printf("[DEATH (cy:%04u)]: Process %04u (player %d) hadn't lived \
for %u cycles (CTD: %d)\n", global_timer(CHECK), (*ptr_proc)->pid, \
(*ptr_proc)->champ.id, global_timer(CHECK) - (*ptr_proc)->life.last, \
deadline(CHECK));
	proc_pop(proc_hdr(CHECK), *ptr_proc);
}

void	atropos(t_proc **p)
{
	if (!p)
		return ;
	foreach_proc(p, &kill_proc);
}
