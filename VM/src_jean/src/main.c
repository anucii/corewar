/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 14:54:08 by jgonthie          #+#    #+#             */
/*   Updated: 2018/01/05 15:51:52 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

unsigned int	g_n_players = 0;

int				main(int argc, char **argv)
{
	t_proc			**p;
	t_info			*info;
	unsigned char	*arena;
	int				ch;

	ch = 0;
	arena = NULL;
	p = ft_memalloc(sizeof(t_proc));
	info = check_arg(&p, &arena, argv, argc);
	get_info(&info);
	if (!info->opt[0])
		intr_msg(p);
	run(arena, p);
	if (info->opt[0])
	{
		destroy_win(info);
		endwin();
	}
	lives_reg(CHECK, 0, info, NULL);
	return (0);
}
