/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 09:31:30 by jgonthie          #+#    #+#             */
/*   Updated: 2018/02/16 16:15:35 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	draw_player(t_info *info, t_proc **proc, _Bool init)
{
	t_proc			*tmp;
	int				pos;

	tmp = (*proc);
	pos = 2;
	while (tmp)
	{
		if (init && id_is_new(CHECK, tmp->champ.id))
		{
			mvwprintw(info->win, BORDER_ARENA_Y + pos, 5, "Player ");
			wprintw(info->win, store_nb(INCR, ft_itoa(tmp->champ.id)));
			wprintw(info->win, " : ");
			wattron(info->win, COLOR_PAIR(tmp->color));
			wprintw(info->win, tmp->champ.name);
			wattroff(info->win, COLOR_PAIR(tmp->color));
			pos += 2;
		}
		tmp = tmp->next;
	}
	mvwprintw(info->win, 12, BORDER_ARENA_X + 5, "Processes : ");
	wprintw(info->win, store_nb(INCR, ft_itoa(count_proc(proc))));
	wrefresh(info->win);
	id_is_new(REINIT, INT_MAX);
	store_nb(REINIT, NULL);
}

static void	draw_info(t_info *info)
{
	mvwprintw(info->win, 2, BORDER_ARENA_X + 5, "Press 'Q' to exit");
	mvwprintw(info->win, 3, BORDER_ARENA_X + 5, "Press 'w' to speed up");
	mvwprintw(info->win, 4, BORDER_ARENA_X + 5, "Press 'e' to speed down");
	mvwprintw(info->win, 6, BORDER_ARENA_X + 5, "CYCLE_TO_DIE : ");
	mvwprintw(info->win, 6, BORDER_ARENA_X + 5 + ft_strlen("CYCLE_TO_DIE : "),\
			"    ");
	mvwprintw(info->win, 6, BORDER_ARENA_X + 5 + ft_strlen("CYCLE_TO_DIE : "),\
			store_nb(INCR, ft_itoa(deadline(CHECK))));
	mvwprintw(info->win, 7, BORDER_ARENA_X + 5, "CYCLE_DELTA : ");
	wprintw(info->win, store_nb(INCR, ft_itoa(CYCLE_DELTA)));
	mvwprintw(info->win, 8, BORDER_ARENA_X + 5, "NBR_LIVE : ");
	wprintw(info->win, store_nb(INCR, ft_itoa(nbr_live(CHECK))));
	mvwprintw(info->win, 9, BORDER_ARENA_X + 5, "MAX_CHECKS : ");
	wprintw(info->win, store_nb(INCR, ft_itoa(MAX_CHECKS)));
	mvwprintw(info->win, 10, BORDER_ARENA_X + 5, "Cycle : ");
	wprintw(info->win, store_nb(INCR, ft_itoa(global_timer(CHECK))));
	wrefresh(info->win);
	store_nb(REINIT, NULL);
}

void		draw_corewar(t_info *info, t_proc **proc)
{
	static _Bool	init = 1;

	id_is_new(REINIT, INT_MAX);
	draw_info(info);
	draw_player(info, proc, init);
	init = 0;
	draw_info_player(info, proc);
	return ;
}
