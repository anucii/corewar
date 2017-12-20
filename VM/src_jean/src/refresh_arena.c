/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_arena.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:26:19 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/20 15:16:31 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static char	*conv_to_print(unsigned char c)
{
	char	*tmp;
	char	*s;

	s = ft_strbase(c, "0123456789abcdef");
	tmp = NULL;
	if (ft_strlen(s) == 1)
	{
		tmp = ft_strdup(s);
		ft_strdel(&s);
		s = ft_strjoin("0", tmp);
		ft_strdel(&tmp);
	}
	return (s);
}

void		refresh_arena(t_win *w, unsigned char *arena, int color)
{
	int				index;
	int				line;
	int				len;
	int				tmp;

	wattron(w->win, COLOR_PAIR(color));
	if (w->start <= w->end)
		len = w->end - w->start;
	else
		len = MEM_SIZE - (w->start - w->end);
	index = w->start;
	tmp = w->start;
	line = w->start / 64;
	if (w->start > 64)
	{
		w->start = w->start - (64 * line);
		w->start = w->start * 3;
	}
	while (len-- > 0)
	{
		mvwprintw(w->win, line + 2, w->start + 2, conv_to_print(arena[index]));
		w->start += 3;
		if (w->start % 64 == 0)
		{
			w->start = 0;
			line++;
			if (line == 64)
				line = 0;
		}
		index++;
		wrefresh(w->win);
	}
	wattroff(w->win, COLOR_PAIR(color));
}
