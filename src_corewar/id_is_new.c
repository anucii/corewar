/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_is_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 16:37:27 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/12 17:14:09 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

_Bool	id_is_new(t_req req, int val)
{
	static int	ctrl[MAX_PLAYERS + 1] = {INT_MAX};
	static int	i = -1;
	int			j;

	j = -1;
	if (req == CHECK)
	{
		while (++j < MAX_PLAYERS)
			if (ctrl[j] == val)
				return (0);
		ctrl[++i] = val;
	}
	else if (req == REINIT)
	{
		i = -1;
		while (++j < MAX_PLAYERS)
			ctrl[j] = INT_MAX;
	}
	return (1);
}
