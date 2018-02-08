/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:22:45 by jgonthie          #+#    #+#             */
/*   Updated: 2018/02/08 13:55:19 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	update_val(int *count_col, _Bool *print)
{
	*count_col += 3;
	*print = 0;
}

void		init_arena(t_info *info, unsigned char *arena)
{
	int				count_line;
	int				count_col;
	_Bool			print;

	wattron(info->win, COLOR_PAIR(5));
	count_line = 1;
	while (++count_line + 1 < BORDER_ARENA_Y)
	{
		print = 1;
		count_col = 2;
		while (count_col < BORDER_ARENA_X - 1)
		{
			if (print)
				mvwprintw(info->win, count_line, count_col, "00");
			else
			{
				wprintw(info->win, " ");
				wprintw(info->win, "00");
			}
			update_val(&count_col, &print);
			arena++;
		}
	}
	wattroff(info->win, COLOR_PAIR(5));
	wrefresh(info->win);
}
