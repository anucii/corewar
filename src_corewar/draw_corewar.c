/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 09:31:30 by jgonthie          #+#    #+#             */
/*   Updated: 2018/01/31 13:47:42 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	draw_info_player(t_info *info, t_proc **proc, int color)
{
	t_proc	*tmp;
	int			y;

	y = 18;
	tmp = (*proc);
	while (tmp)
	{
		wattron(info->win, A_STANDOUT);
		wattron(info->win, COLOR_PAIR(color));
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
		wprintw(info->win, ft_itoa(0));
		mvwprintw(info->win, y + 8, BORDER_ARENA_X + 5, "Lives in current period : ");
		wprintw(info->win, ft_itoa(0));
		color++;
		tmp = tmp->next;
		y += 12;
	}
	wrefresh(info->win);
}

static void	draw_player(t_info *info, t_proc **proc, int color)
{
	t_proc	*tmp;
	int		nb_player;
	int		pos;

	tmp = (*proc);
	nb_player = -1;
	pos = 2;
	while (tmp)
	{
		mvwprintw(info->win, BORDER_ARENA_Y + pos, 5, "Player ");
		wprintw(info->win, ft_itoa(nb_player));
		wprintw(info->win, " : ");
		wattron(info->win, COLOR_PAIR(color));
		wprintw(info->win, tmp->champ.name);
		wattroff(info->win, COLOR_PAIR(color));
		nb_player--;
		pos += 2;
		color++;
		tmp = tmp->next;
	}
	mvwprintw(info->win, 12, BORDER_ARENA_X + 5, "Processes : ");
	wprintw(info->win, ft_itoa(nb_player * (-1) - 1));
	wrefresh(info->win);
}

static void	draw_info(t_info *info)
{
	mvwprintw(info->win, 2, BORDER_ARENA_X + 5, "Press 'Q' to exit");
	mvwprintw(info->win, 3, BORDER_ARENA_X + 5, "Press 'w' to speed up");
	mvwprintw(info->win, 4, BORDER_ARENA_X + 5, "Press 'e' to speed down");
	mvwprintw(info->win, 6, BORDER_ARENA_X + 5, "CYCLE_TO_DIE : ");
	wprintw(info->win, ft_itoa(CYCLE_TO_DIE));
	mvwprintw(info->win, 7, BORDER_ARENA_X + 5, "CYCLE_DELTA : ");
	wprintw(info->win, ft_itoa(CYCLE_DELTA));
	mvwprintw(info->win, 8, BORDER_ARENA_X + 5, "NBR_LIVE : ");
	wprintw(info->win, ft_itoa(NBR_LIVE));
	mvwprintw(info->win, 9, BORDER_ARENA_X + 5, "MAX_CHECKS : ");
	wprintw(info->win, ft_itoa(MAX_CHECKS));
	mvwprintw(info->win, 10, BORDER_ARENA_X + 5, "Cycles/second limit : ");
	wprintw(info->win, ft_itoa(CYCLE_DELTA));
	mvwprintw(info->win, 11, BORDER_ARENA_X + 5, "Cycle : ");
	wprintw(info->win, ft_itoa(0));
	wrefresh(info->win);
}

void		draw_corewar(t_info *info, t_proc **proc)
{
	int		color;

	color = 1;
	draw_info(info);
	draw_player(info, proc, color);
	draw_info_player(info, proc, color);
	return ; 
}
