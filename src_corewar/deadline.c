/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deadline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 20:15:53 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/07 20:38:13 by jdaufin          ###   ########.fr       */
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

int				deadline(t_req request)
{
	static int			ret = CYCLE_TO_DIE;
	static unsigned int checks = 0;
	t_info				*info;

	if (request == DECR)
	{
		info = get_info(NULL);
		checks++;
		if (info->opt[3] && info->opt[4] && !info->opt[0])
			ft_printf("[DEADLINE (cy:%u)]: %u lives recorded (check no %u), \
new CTD = ", global_timer(CHECK), nbr_live(CHECK), checks);
		if ((nbr_live(CHECK) >= NBR_LIVE) || (checks == MAX_CHECKS))
		{
			ret -= CYCLE_DELTA;
			if (info->opt[3] && info->opt[4] && !info->opt[0])
				ft_printf("%d\n", ret);
			checks = 0;
			init_ll(get_info(NULL));
		}
		else if (info->opt[3] && info->opt[4] && !info->opt[0])
			ft_printf("old CTD (ie %d)\n", ret);
		nbr_live(REINIT);
	}
	return (ret);
}
