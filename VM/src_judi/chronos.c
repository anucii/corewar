/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chronos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:30:38 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/13 15:24:59 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "judi.h"

_Bool	chronos(t_proc *proc, t_req request, unsigned int player)
{
	if (!proc)
		return (0);
	if (request == LIVE)
	{
		proc->life.status = 1;
		proc->life.last = timer(CHECK);
		proc->life.player = player;
	}
	else if (request == CHECK)
		return ((proc->life.player == player) && proc->life.status);
	return (0);
}
