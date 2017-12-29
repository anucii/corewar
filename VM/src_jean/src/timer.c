/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:48:48 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/29 15:46:19 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Timer function, 
**	- increments the clock only if called with request INCR,
**	- reinitializes the clock if called with REINIT
**	- returns the current clock value otherwise
*/

unsigned int	timer(t_req request)
{
	static unsigned int	clock = 0;

	if (request == INCR)
	{
		clock++;
		global_timer(INCR);
	}
	else if (request == REINIT)
		clock = 0;
	return (clock);
}

unsigned int	global_timer(t_req request)
{
	static unsigned int	gl_clock = 0;

	if (request == INCR)
		gl_clock++;
	return (gl_clock);
}
