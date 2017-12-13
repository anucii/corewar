/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deadline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 20:15:53 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/13 20:26:20 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "judi.h"

/*
**	nbr_live() counts the number of declared live during a series of cycles
*/

unsigned int	nbr_live(t_req request)
{
	static unsigned int ret = 0;

	if (request == INCR)
		ret++;
	if (request == RESET)
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

	if ((request == DECR) && (nbr_live(CHECK) >= NBR_LIVE))
		ret -= CYCLE_DELTA;
	return (ret);
}
