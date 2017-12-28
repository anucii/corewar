/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deadline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 20:15:53 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/28 18:33:15 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	nbr_live() counts the number of declared live during a series of cycles
*/

unsigned int	nbr_live(t_req request)
{
	static unsigned int ret = 0;

	if (request == INCR)
		ret++;
	if (request == REINIT)
		ret = 0;
	return (ret);
}

/*
**	deadline() manages the end of cycles threshold, decreasing by CYCLE_DELTA
**	when at least NBR_LIVE lives had been executed since the last checking (cf
**	run.c)
*/

unsigned int	deadline(t_req request)
{
	static unsigned int	ret = CYCLE_TO_DIE;
	static unsigned int checks = 0;

	if (request == DECR)
	{
		checks++;
		if ((nbr_live(CHECK) >= NBR_LIVE) || (checks == MAX_CHECKS))
		{
			ret -= CYCLE_DELTA;
			checks = 0;
		}
	}
	return (ret);
}
