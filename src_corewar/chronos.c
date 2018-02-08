/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chronos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:30:38 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/08 12:16:02 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

_Bool	chronos(t_proc *proc, t_req request, unsigned int player)
{
	t_info	*info;

	if (!proc)
		return (0);
	if (request == LIVE)
	{
		info = get_info(NULL);
		proc->life.status = 1;
		proc->life.last = global_timer(CHECK);
		proc->life.player = player;
		(proc->life.cur)++;
		nbr_live(INCR);
		if (info)
			lives_reg(LIVE, player, info, proc);
		return (1);
	}
	else if (request == CHECK)
		return (proc->life.status);
	return (0);
}
