/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:57:12 by jgonthie          #+#    #+#             */
/*   Updated: 2018/02/08 14:16:32 by jdaufin          ###   ########.fr       */
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

void		draw_arena(t_info *info, unsigned char *arena, int color)
{
	static int		line = 0;
	int				index;
	int				len;
	char			*s;

	wattron(info->win, COLOR_PAIR(color));
	len = info->end - info->start;
	index = info->start;
	while (len-- > 0)
	{
		mvwprintw(info->win, line + 2, info->start + 2, s = \
				conv_to_print(arena[index]));
		mvwprintw(info->win, line + 2, info->start + 4, " ");
		info->start += 3;
		if (info->start % 64 == 0)
		{
			info->start = 0;
			line++;
		}
		index++;
		wrefresh(info->win);
		ft_strdel(&s);
	}
	line--;
	wattroff(info->win, COLOR_PAIR(color));
}
