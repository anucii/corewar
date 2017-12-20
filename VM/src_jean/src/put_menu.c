/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_menu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:00:06 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/18 14:21:55 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	print_corewar(t_win *w)
{
	mvwprintw(w->win, (HEIGHT_WIN / 2) - 12, 75, " ________  ________  ________  _______   ___       __   ________  ________     ");
	mvwprintw(w->win, (HEIGHT_WIN / 2) - 11, 75, "|\\   ____\\|\\   __  \\|\\   __  \\|\\  ___ \\ |\\  \\     |\\  \\|\\   __  \\|\\   __  \\    ");
	mvwprintw(w->win, (HEIGHT_WIN / 2) - 10, 75, "\\ \\  \\___|\\ \\  \\|\\  \\ \\  \\|\\  \\ \\   __/|\\ \\  \\    \\ \\  \\ \\  \\|\\  \\ \\  \\|\\  \\   ");
	mvwprintw(w->win, (HEIGHT_WIN / 2) - 9, 75, " \\ \\  \\    \\ \\  \\\\\\  \\ \\   _  _\\ \\  \\_|/_\\ \\  \\  __\\ \\  \\ \\   __  \\ \\   _  _\\  ");
	mvwprintw(w->win, (HEIGHT_WIN / 2) - 8, 75, "  \\ \\  \\____\\ \\  \\\\\\  \\ \\  \\\\  \\\\ \\  \\_|\\ \\ \\  \\|\\__\\_\\  \\ \\  \\ \\  \\ \\  \\\\  \\| ");
	mvwprintw(w->win, (HEIGHT_WIN / 2) - 7, 75, "   \\ \\_______\\ \\_______\\ \\__\\\\ _\\\\ \\_______\\ \\____________\\ \\__\\ \\__\\ \\__\\\\ _\\ ");
	mvwprintw(w->win, (HEIGHT_WIN / 2) - 6, 75, "    \\|_______|\\|_______|\\|__|\\|__|\\|_______|\\|____________|\\|__|\\|__|\\|__|\\|__|");
}

static void	draw_menu(t_win *w)
{
	wattron(w->win, COLOR_PAIR(3));
	print_corewar(w);
	wattron(w->win, A_UNDERLINE);
	mvwprintw(w->win, (HEIGHT_WIN / 2) + 3, 106, "PRESS SPACE TO BEGIN");
	wattroff(w->win, A_UNDERLINE);
	mvwprintw(w->win, 70, 10, "By : JDaufin");
	mvwprintw(w->win, 72, 10, "     JPallard");
	mvwprintw(w->win, 74, 10, "     JGonthie");
	wrefresh(w->win);
	while (getch() != ' ')
		;
	wattroff(w->win, COLOR_PAIR(3));
}

void		put_menu(t_win *w)
{
	new_win(w, MENU);
	draw_menu(w);
	destroy_win(w);
}
