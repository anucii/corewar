/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deadline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 20:15:53 by jdaufin           #+#    #+#             */
/*   Updated: 2018/01/05 17:58:19 by jdaufin          ###   ########.fr       */
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
	t_info				*info;

	if (request == DECR)
	{
		info = get_info(NULL);
		checks++;
		if (info->opt[3] && !info->opt[0])
			ft_printf("[DEADLINE (cy:%u)]: %u lives recorded (check no %u)\n",\
					global_timer(CHECK), nbr_live(CHECK), checks);
		if ((nbr_live(CHECK) >= NBR_LIVE) || (checks == MAX_CHECKS))
		{
			if (ret > CYCLE_DELTA)
				ret -= CYCLE_DELTA;
			checks = 0;
			nbr_live(REINIT);
			init_ll(get_info(NULL));
		}
	}
	return (ret);
}
