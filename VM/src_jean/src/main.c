/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 14:54:08 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/21 15:00:06 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

_Bool			g_print = 0;
unsigned int	g_n_players = 0;

int				main(int argc, char **argv)
{
	t_proc			**p;
	t_win			*w;
	unsigned char	*arena;
	int				ch;

	ch = 0;
	arena = NULL;
	p = ft_memalloc(sizeof(t_proc));
	w = check_arg(&p, &arena, argv, argc);
	run(arena, p);
	if (g_print)
	{
		while (1)
		{
			if ((ch = wgetch(w->win)) == 'Q')
			{
				destroy_win(w);
				endwin();
				break ;
			}
		}
	}
	return (0);
}
