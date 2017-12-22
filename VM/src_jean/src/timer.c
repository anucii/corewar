/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:48:48 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/21 17:19:14 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Global timer function, 
**	- increments the clock only if called with request INCR,
**	- reinitializes the clock if called with REINIT
**	- returns the current clock value otherwise
*/

unsigned int	timer(t_req request)
{
	static unsigned int	clock = 0;

	if (request == INCR)
		clock++;
	else if (request == REINIT)
		clock = 0;
	return (clock);
}
