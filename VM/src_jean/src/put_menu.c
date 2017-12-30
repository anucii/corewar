/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_menu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:00:06 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/30 16:29:27 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	print_corewar(t_info *info)
{
	mvwprintw(info->win, (HEIGHT_WIN / 2) - 12, 75, " ________  ________  ________  _______   ___       __   ________  ________     ");
	mvwprintw(info->win, (HEIGHT_WIN / 2) - 11, 75, "|\\   ____\\|\\   __  \\|\\   __  \\|\\  ___ \\ |\\  \\     |\\  \\|\\   __  \\|\\   __  \\    ");
	mvwprintw(info->win, (HEIGHT_WIN / 2) - 10, 75, "\\ \\  \\___|\\ \\  \\|\\  \\ \\  \\|\\  \\ \\   __/|\\ \\  \\    \\ \\  \\ \\  \\|\\  \\ \\  \\|\\  \\   ");
	mvwprintw(info->win, (HEIGHT_WIN / 2) - 9, 75, " \\ \\  \\    \\ \\  \\\\\\  \\ \\   _  _\\ \\  \\_|/_\\ \\  \\  __\\ \\  \\ \\   __  \\ \\   _  _\\  ");
	mvwprintw(info->win, (HEIGHT_WIN / 2) - 8, 75, "  \\ \\  \\____\\ \\  \\\\\\  \\ \\  \\\\  \\\\ \\  \\_|\\ \\ \\  \\|\\__\\_\\  \\ \\  \\ \\  \\ \\  \\\\  \\| ");
	mvwprintw(info->win, (HEIGHT_WIN / 2) - 7, 75, "   \\ \\_______\\ \\_______\\ \\__\\\\ _\\\\ \\_______\\ \\____________\\ \\__\\ \\__\\ \\__\\\\ _\\ ");
	mvwprintw(info->win, (HEIGHT_WIN / 2) - 6, 75, "    \\|_______|\\|_______|\\|__|\\|__|\\|_______|\\|____________|\\|__|\\|__|\\|__|\\|__|");
}

static void	draw_menu(t_info *info)
{
	wattron(info->win, COLOR_PAIR(3));
	print_corewar(info);
	wattron(info->win, A_UNDERLINE);
	mvwprintw(info->win, (HEIGHT_WIN / 2) + 3, 106, "PRESS SPACE TO BEGIN");
	wattroff(info->win, A_UNDERLINE);
	mvwprintw(info->win, 70, 10, "By : JDaufin");
	mvwprintw(info->win, 72, 10, "     JPallard");
	mvwprintw(info->win, 74, 10, "     JGonthie");
	wrefresh(info->win);
	while (getch() != ' ')
		;
	wattroff(info->win, COLOR_PAIR(3));
}

void		put_menu(t_info *info)
{
	FMOD_SYSTEM *system;
	FMOD_SOUND *bgm;
	FMOD_RESULT res;

	FMOD_System_Create(&system);
	FMOD_System_Init(system, 1, FMOD_INIT_NORMAL, NULL);
	res = FMOD_System_CreateSound(system, "./include/AR.mp3", FMOD_LOOP_NORMAL, 0, &bgm);
	if (res != FMOD_OK)
	{
		ft_printf("FUCCCCCCCCCCCCCCCCCCK\n");
		exit(EXIT_FAILURE);
	}
	FMOD_Sound_SetLoopCount(bgm, -1);
	FMOD_System_PlaySound(system, bgm, 0, false, NULL);
	new_win(info, MENU);
	draw_menu(info);
	destroy_win(info);
}
