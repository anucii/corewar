/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 09:31:30 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/18 17:52:30 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	draw_live(t_win *w)
{
	mvwprintw(w->win, BORDER_ARENA_Y + 2, 165, "Live breakdown for current period :");
	mvwprintw(w->win, BORDER_ARENA_Y + 4, 155, "[-----------------------------------------------------]");
	mvwprintw(w->win, BORDER_ARENA_Y + 6, 165, "Live breakdown for last period :");
	mvwprintw(w->win, BORDER_ARENA_Y + 8, 155, "[-----------------------------------------------------]");
	wrefresh(w->win);
}

static void	draw_info_player(t_win *w, t_proc **proc, int color)
{
	int			y;

	y = 18;
	while (*proc)
	{
		wattron(w->win, A_STANDOUT);
		wattron(w->win, COLOR_PAIR(color));
		mvwprintw(w->win, y, BORDER_ARENA_X + 14, "   ");
		mvwprintw(w->win, y, BORDER_ARENA_X + 19, "    ");
		mvwprintw(w->win, y + 1, BORDER_ARENA_X + 13, "   ");
		mvwprintw(w->win, y + 1, BORDER_ARENA_X + 18, "      ");
		mvwprintw(w->win, y + 2, BORDER_ARENA_X + 15, " ");
		mvwprintw(w->win, y + 2, BORDER_ARENA_X + 17, "    ");
		mvwprintw(w->win, y + 2, BORDER_ARENA_X + 22, "  ");
		mvwprintw(w->win, y + 3, BORDER_ARENA_X + 17, "   ");
		mvwprintw(w->win, y + 3, BORDER_ARENA_X + 21, " ");
		mvwprintw(w->win, y + 4, BORDER_ARENA_X + 18, "  ");
		wattroff(w->win, COLOR_PAIR(color));
		wattroff(w->win, A_STANDOUT);
		mvwprintw(w->win, y + 7, BORDER_ARENA_X + 5, "Last live : ");
		wprintw(w->win, ft_itoa(0));
		mvwprintw(w->win, y + 8, BORDER_ARENA_X + 5, "Lives in current period : ");
		wprintw(w->win, ft_itoa(0));
		color++;
		proc++;
		y += 12;
	}
	wrefresh(w->win);
}

static void	draw_player(t_win *w, t_proc **proc, int color)
{
	int		nb_player;
	int		pos;

	nb_player = -1;
	pos = 2;
	while (*proc)
	{
		mvwprintw(w->win, BORDER_ARENA_Y + pos, 5, "Player ");
		wprintw(w->win, ft_itoa(nb_player));
		wprintw(w->win, " : ");
		wattron(w->win, COLOR_PAIR(color));
		wprintw(w->win, (*proc)->name);
		wattroff(w->win, COLOR_PAIR(color));
		nb_player--;
		pos += 2;
		color++;
		proc++;
	}
	mvwprintw(w->win, 12, BORDER_ARENA_X + 5, "Processes : ");
	wprintw(w->win, ft_itoa(nb_player * (-1) - 1));
	wrefresh(w->win);
}

static void	draw_info(t_win *w)
{
	mvwprintw(w->win, 2, BORDER_ARENA_X + 5, "Press 'Q' to exit");
	mvwprintw(w->win, 4, BORDER_ARENA_X + 5, "CYCLE_TO_DIE : ");
	wprintw(w->win, ft_itoa(CYCLE_TO_DIE));
	mvwprintw(w->win, 6, BORDER_ARENA_X + 5, "CYCLE_DELTA : ");
	wprintw(w->win, ft_itoa(CYCLE_DELTA));
	mvwprintw(w->win, 8, BORDER_ARENA_X + 5, "NBR_LIVE : ");
	wprintw(w->win, ft_itoa(NBR_LIVE));
	mvwprintw(w->win, 10, BORDER_ARENA_X + 5, "MAX_CHECKS : ");
	wprintw(w->win, ft_itoa(MAX_CHECKS));
	mvwprintw(w->win, 14, BORDER_ARENA_X + 5, "Cycles/second limit : ");
	wprintw(w->win, ft_itoa(CYCLE_DELTA));
	mvwprintw(w->win, 16, BORDER_ARENA_X + 5, "Cycle : ");
	wprintw(w->win, ft_itoa(0));
	wrefresh(w->win);
}

void		draw_corewar(t_win *window, t_proc **proc)
{
	int		color;

	color = 1;
	draw_info(window);
	draw_player(window, proc, color);
	draw_info_player(window, proc, color);
	draw_live(window);
}
