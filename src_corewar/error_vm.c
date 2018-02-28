/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_vm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:52:38 by jpallard          #+#    #+#             */
/*   Updated: 2018/02/27 18:01:05 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_usage(char *s)
{
	if (ft_strlen(s) > 0)
		ft_printf(RED"%s\n"RESET, s);
	ft_printf(""RED"Usage:"RESET"\n\
./corewar ["BLACK"-c"RESET"] ["GREEN"-n"RESET" number] ["PURPLE"-dump"RESET" \
number] ["CYAN"-v"RESET" number] <champ.cor> <...> \
[%d players max]\n"YELLOW"### OPTION ###"RESET"\n\
"BLACK"-c"RESET"	: nCurses output mode\n\
"GREEN"-n"RESET"	: number of player\n\
"PURPLE"-dump"RESET"	: dumps memory after N cycles then exits\n\
"CYAN"-v"RESET"	: verbos output mode", MAX_PLAYERS);
	error_vm("");
}

void	error_vm(char *s)
{
	t_info	*info;

	info = get_info(NULL);
	ft_printf(RED"%s\n"RESET, s);
	if (info && info->opt[0])
	{
		destroy_win(info);
		endwin();
		free_music(info);
	}
	exit(EXIT_FAILURE);
}
