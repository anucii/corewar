/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 09:31:30 by jgonthie          #+#    #+#             */
/*   Updated: 2018/02/07 20:59:39 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	draw_info_player(t_info *info, t_proc **proc, int color)
{
	t_proc	*tmp;
	int		y;
	int		*val[2];	

	y = 18;
	tmp = (*proc);
	val[0] = NULL;
	while (tmp)
	{
		if (id_is_new(CHECK, tmp->champ.id))
		{
			val[1] = &(tmp->champ.id);
			wattron(info->win, A_STANDOUT);
			wattron(info->win, COLOR_PAIR(tmp->color));
			mvwprintw(info->win, y, BORDER_ARENA_X + 14, "   ");
			mvwprintw(info->win, y, BORDER_ARENA_X + 19, "    ");
			mvwprintw(info->win, y + 1, BORDER_ARENA_X + 13, "   ");
			mvwprintw(info->win, y + 1, BORDER_ARENA_X + 18, "      ");
			mvwprintw(info->win, y + 2, BORDER_ARENA_X + 15, " ");
			mvwprintw(info->win, y + 2, BORDER_ARENA_X + 17, "    ");
			mvwprintw(info->win, y + 2, BORDER_ARENA_X + 22, "  ");
			mvwprintw(info->win, y + 3, BORDER_ARENA_X + 17, "   ");
			mvwprintw(info->win, y + 3, BORDER_ARENA_X + 21, " ");
			mvwprintw(info->win, y + 4, BORDER_ARENA_X + 18, "  ");
			wattroff(info->win, COLOR_PAIR(color));
			wattroff(info->win, A_STANDOUT);
			mvwprintw(info->win, y + 7, BORDER_ARENA_X + 5, "Last live : ");
			wprintw(info->win, store_nb(INCR, ft_itoa(player_lives(CHECK, &val, info, tmp))));
			mvwprintw(info->win, y + 8, BORDER_ARENA_X + 5, "Lives in current period : ");
			wprintw(info->win, store_nb(INCR, ft_itoa(player_lives(NONE, &val, info, tmp))));
			color++;
			y += 12;
		}
		tmp = tmp->next;
	}
	store_nb(REINIT, NULL);
	id_is_new(REINIT, INT_MAX);
	wrefresh(info->win);
}

static void	draw_player(t_info *info, t_proc **proc, int color)
{
	t_proc			*tmp;
	int				pos;
	static _Bool	init = 1;

	tmp = (*proc);
	pos = 2;
	if (init)
		while (tmp)
		{
			if (id_is_new(CHECK, tmp->champ.id))
			{
				mvwprintw(info->win, BORDER_ARENA_Y + pos, 5, "Player ");
				wprintw(info->win, store_nb(INCR, ft_itoa(tmp->champ.id)));
				wprintw(info->win, " : ");
				wattron(info->win, COLOR_PAIR(color));
				wprintw(info->win, tmp->champ.name);
				wattroff(info->win, COLOR_PAIR(color));
				pos += 2;
				color++;
			}
			tmp = tmp->next;
			init = 0;
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
	wprintw(info->win, store_nb(INCR, ft_itoa(deadline(CHECK))));
	mvwprintw(info->win, 7, BORDER_ARENA_X + 5, "CYCLE_DELTA : ");
	wprintw(info->win, store_nb(INCR, ft_itoa(CYCLE_DELTA)));
	mvwprintw(info->win, 8, BORDER_ARENA_X + 5, "NBR_LIVE : ");
	wprintw(info->win, store_nb(INCR, ft_itoa(nbr_live(CHECK))));
	mvwprintw(info->win, 9, BORDER_ARENA_X + 5, "MAX_CHECKS : ");
	wprintw(info->win, store_nb(INCR, ft_itoa(MAX_CHECKS)));
	mvwprintw(info->win, 10, BORDER_ARENA_X + 5, "Cycles/second limit : ");
	wprintw(info->win, store_nb(INCR, ft_itoa(CYCLE_DELTA)));
	mvwprintw(info->win, 11, BORDER_ARENA_X + 5, "Cycle : ");
	wprintw(info->win, store_nb(INCR, ft_itoa(global_timer(CHECK))));
	wrefresh(info->win);
	store_nb(REINIT, NULL);
}

void		draw_corewar(t_info *info, t_proc **proc)
{
	int		color;

	color = 1;
	id_is_new(REINIT, INT_MAX);
	draw_info(info);
	draw_player(info, proc, color);
	draw_info_player(info, proc, color);
	return ; 
}
