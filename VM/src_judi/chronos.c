/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chronos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:30:38 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/12 15:54:48 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "judi.h"

_Bool	chronos(t_proc *proc, t_req request)
{
	if (!proc)
		return (0);
	if (request == LIVE)
	{
		proc->life.status = 1;
		proc->life.last = timer();
	}
	else if (request == CHECK)
		return (proc->life.status);
	return (0);
}
