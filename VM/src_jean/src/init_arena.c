/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:22:45 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/20 16:24:41 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		init_arena(t_win *w, unsigned char *arena)
{
	int				count_line;
	int				count_col;
	int				index;
	_Bool			print;

	wattron(w->win, COLOR_PAIR(5));
	count_line = 1;
	index = -1;
	while (++count_line + 1 < BORDER_ARENA_Y)
	{
		index = -1;
		print = 1;
		count_col = 2;
		while (count_col < BORDER_ARENA_X - 1)
		{
			if (print)
				mvwprintw(w->win, count_line, count_col, "00");
			else
			{
				wprintw(w->win, " ");
				wprintw(w->win, "00");
			}
			count_col += 3;
			print = 0;
			arena++;
		}
	}
	wattroff(w->win, COLOR_PAIR(5));
	wrefresh(w->win);
}
