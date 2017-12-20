/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:57:12 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/20 16:19:26 by jgonthie         ###   ########.fr       */
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

void		draw_arena(t_win *w, unsigned char *arena, int color)
{
	static int		line = 0;
	int				index;
	int				len;

	wattron(w->win, COLOR_PAIR(color));
	len = w->end - w->start;
	index = w->start;
	while (len-- > 0)
	{
		mvwprintw(w->win, line + 2, w->start + 2, conv_to_print(arena[index]));
		mvwprintw(w->win, line + 2, w->start + 4, " ");
		w->start += 3;
		if (w->start % 64 == 0)
		{
			w->start = 0;
			line++;
		}
		index++;
		wrefresh(w->win);
	}
	line--;
	wattroff(w->win, COLOR_PAIR(color));
}
