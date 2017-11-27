/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_order_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:09:09 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/27 17:18:03 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "judi.h"

void	write_order_pos(t_order *tab, int max)
{
	int 	i;
	short	step;

	if (!tab)
		exit(EXIT_FAILURE);
		//ft_error("[ERR] : null pointer passed as orders array");
	i = -1;
	step = 0;
	while (++i < max)
	{
		step = i ? tab[i - 1].pos + tab[i - 1].size : 0;
		tab[i].pos = step;
	}
}
