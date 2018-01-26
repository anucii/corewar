/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_order_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:09:09 by jdaufin           #+#    #+#             */
/*   Updated: 2018/01/26 14:42:19 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_order_pos(t_order **tab, t_file *file, int last)
{
	int		i;
	short	step;

	if (!(tab && *tab))
	{
		if (file->line)
			error_file(file->line);
		else
			error("[ERR] : Empty file");
	}
	i = -1;
	step = 0;
	while (++i < last)
	{
		step = i ? tab[i - 1]->pos + tab[i - 1]->size : 0;
		tab[i]->pos = step;
	}
}
