/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_names.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 17:59:07 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/08 14:19:25 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Function designed to store the output of the calls to strdup on the
**	champions binary file name field. It thus allows us to cleanly free
**	the allocated strings at the end of the game (which cannot be made from the
**	processes, as siblings share a unique pointer to characters => double free
**	error)
*/

char	*store_names(t_req req, char *name)
{
	static char		*store[MAX_PLAYERS + 1] = {0};
	static ssize_t	i = -1;
	ssize_t			j;

	if (name && req == INCR)
	{
		store[++i] = name;
		return (store[i]);
	}
	else if (req == CLEAR)
	{
		j = MAX_PLAYERS;
		while (--j > -1)
			if (store[j])
				ft_strdel(&store[j]);
	}
	return (NULL);
}
