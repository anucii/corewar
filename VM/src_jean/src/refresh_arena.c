/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_arena.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:26:19 by jgonthie          #+#    #+#             */
/*   Updated: 2018/01/03 17:34:23 by jdaufin          ###   ########.fr       */
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

void		refresh_arena(t_info *info, unsigned char *arena, int color)
{
	int				index;
	int				line;
	int				len;
	int				tmp;

	wattron(info->win, COLOR_PAIR(color));
	if (info->start <= info->end)
		len = info->end - info->start;
	else
		len = MEM_SIZE - (info->start - info->end);
	index = info->start;
	tmp = info->start;
	line = info->start / 64;
	if (info->start > 64)
		info->start = info->start - (64 * line);
	info->start = info->start * 3;
	while (len-- > 0)
	{
		mvwprintw(info->win, line + 2, info->start + 2, conv_to_print(arena[index]));
		info->start += 3;
		if (info->start % 64 == 0)
		{
			info->start = 0;
			line++;
			if (line == 64)
				line = 0;
		}
		index++;
		wrefresh(info->win);
	}
	wattroff(info->win, COLOR_PAIR(color));
}
