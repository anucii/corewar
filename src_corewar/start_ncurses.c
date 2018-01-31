/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_ncurses.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:10:08 by jgonthie          #+#    #+#             */
/*   Updated: 2018/01/31 12:53:14 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	color(void)
{
	start_color();
	use_default_colors();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	init_color(COLOR_BLUE, 000, 000, 700);
}

void		start_ncurses(t_info *info, t_proc **proc)
{
	if (initscr() == NULL)
		error_vm("Ft.initsrc() in curses.h failed");
	if (has_colors() == FALSE)
		error_vm("Your terminal does not support color");
	curs_set(0);
	color();
	cbreak();
	noecho();
	refresh();
	put_menu(info);
	init_color(COLOR_BLUE, 400, 400, 400);
	new_win(info, COREWAR);
	draw_corewar(info, proc);
}
