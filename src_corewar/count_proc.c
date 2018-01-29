/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 19:47:48 by jdaufin           #+#    #+#             */
/*   Updated: 2018/01/25 18:29:43 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	store_count(t_req req)
{
	static int	count = 0;

	if (req == INCR)
		++count;
	else if (req == REINIT)
		count = 0;
	return (count);
}

static void	increment(t_proc **p)
{
	if (p && *p)
		store_count(INCR);
}

int			count_proc(t_proc **tab)
{
	int	ret;

	if (!tab)
		return (0);
	foreach_proc(tab, &increment);
	ret = store_count(CHECK);
	store_count(REINIT);
	return (ret);
}
