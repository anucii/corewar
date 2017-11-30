/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_order_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:09:09 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/30 19:17:24 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_order_pos(t_order **tab, int last)
{
	int 	i;
	short	step;

	if (!(tab && *tab))
		error("[ERR] : null tab or pointer passed as orders array");
	i = -1;
	step = 0;
	while (++i < last)
	{
		step = i ? tab[i - 1]->pos + tab[i - 1]->size : 0;
		tab[i]->pos = step;
		ft_printf("tab[%d]->pos = %d\n", i, tab[i]->pos);
	}
}
