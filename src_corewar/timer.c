/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:48:48 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/08 14:08:33 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Timer function,
**	- increments the clock only if called with request INCR,
**	- reinitializes the clock if called with REINIT
**	- returns the current clock value otherwise
*/

int	timer(t_req request)
{
	static int	clock = 1;

	if (request == INCR)
	{
		clock++;
		global_timer(INCR);
	}
	else if (request == REINIT)
		clock = 0;
	return (clock);
}

int	global_timer(t_req request)
{
	static int	gl_clock = 1;

	if (request == INCR)
		gl_clock++;
	return (gl_clock);
}
