/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 10:10:33 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/16 18:13:28 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		new_win(t_win *window, int put)
{
	if ((window->win = newwin(HEIGHT_WIN, WIDTH_WIN, 0, 0)) == NULL)
		error_vm("Ft.newwin in curses.h failed");
	wattron(window->win, A_STANDOUT);
	box(window->win, ' ', ' ');
	wborder(window->win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	if (put == MENU)
	{
		wrefresh(window->win);
		wattroff(window->win, A_STANDOUT);
		return ;
	}
	else if (put == COREWAR)
	{
		mvwvline(window->win, 0, BORDER_ARENA_X, ' ', BORDER_ARENA_Y);
		mvwhline(window->win, BORDER_ARENA_Y, 0, ' ', BORDER_ARENA_X + 1);
		wattroff(window->win, A_STANDOUT);
		wrefresh(window->win);
		wattroff(window->win, A_STANDOUT);
	}
}
