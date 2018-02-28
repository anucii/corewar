/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_arena.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:26:19 by jgonthie          #+#    #+#             */
/*   Updated: 2018/02/27 18:41:25 by jgonthie         ###   ########.fr       */
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

static int	store_line(t_req req, int val)
{
	static int	ret = 0;

	if (req == SETV)
		ret = val;
	if (req == REINIT)
		ret = 0;
	return (ret);
}

static void	refresh_area(t_info *info, unsigned char *arena, int len, int idx)
{
	char	*s;
	int		line;

	line = store_line(CHECK, 0);
	while (len-- > 0)
	{
		mvwprintw(info->win, line + 2, info->start + 2, s = \
				conv_to_print(arena[idx]));
		info->start += 3;
		if (info->start % 64 == 0)
		{
			info->start = 0;
			store_line(SETV, ++line);
			if (line == 64)
				store_line(SETV, line = 0);
		}
		idx++;
		wrefresh(info->win);
		ft_strdel(&s);
	}
}

void		refresh_arena(t_info *info, unsigned char *arena, int color)
{
	int				index;
	int				line;
	int				len;

	wattron(info->win, COLOR_PAIR(color));
	if (info->start <= info->end)
		len = info->end - info->start;
	else
		len = MEM_SIZE - (info->start - info->end);
	index = info->start;
	store_line(SETV, line = info->start / 64);
	if (info->start >= 64)
		info->start = info->start - (64 * line);
	info->start = info->start * 3;
	refresh_area(info, arena, len, index);
	wattroff(info->win, COLOR_PAIR(color));
	store_line(REINIT, 0);
}
