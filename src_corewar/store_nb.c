/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 20:43:50 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/07 20:54:51 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char	*store_nb(t_req req, char *val)
{
	static char	*store[1 + 2 * MAX_PLAYERS] = {0};
	static int	i = -1;
	int			j;

	if (req == INCR)
		store[++i] = val;
	else if (req == REINIT)
	{
		j = -1;
		i = -1;
		while (++j < (1 + 2 * MAX_PLAYERS))
			if (store[j])
				ft_strdel(&store[j]);
	}
	return ((i < (1 + 2 * MAX_PLAYERS)) && (i > -1) ? store[i] : NULL);
}
