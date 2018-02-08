/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 10:10:33 by jgonthie          #+#    #+#             */
/*   Updated: 2018/02/08 13:59:43 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		new_win(t_info *info, int put)
{
	if ((info->win = newwin(HEIGHT_WIN, WIDTH_WIN, 0, 0)) == NULL)
		error_vm("Ft.newwin in curses.h failed");
	wattron(info->win, A_STANDOUT);
	box(info->win, ' ', ' ');
	wborder(info->win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	if (put == MENU)
	{
		wrefresh(info->win);
		wattroff(info->win, A_STANDOUT);
		return ;
	}
	else if (put == COREWAR)
	{
		mvwvline(info->win, 0, BORDER_ARENA_X, ' ', BORDER_ARENA_Y);
		mvwhline(info->win, BORDER_ARENA_Y, 0, ' ', BORDER_ARENA_X + 1);
		wattroff(info->win, A_STANDOUT);
		wrefresh(info->win);
		wattroff(info->win, A_STANDOUT);
	}
}
