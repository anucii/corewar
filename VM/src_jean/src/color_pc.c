/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:22:25 by jgonthie          #+#    #+#             */
/*   Updated: 2018/01/04 18:10:21 by jgonthie         ###   ########.fr       */
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

static void	uncolor_pc(t_proc *proc, t_info *info, unsigned char *mem, int old_pc)
{
	int				line;
	int				x;

	line = old_pc / 64;
	x = old_pc;
	if (x > 64)
		x = x - (64 * line);
	x = x * 3;
	wattron(info->win, COLOR_PAIR(proc->color));
	mvwprintw(info->win, line + 2, x, conv_to_print(mem[old_pc]));
	wrefresh(info->win);
	wattroff(info->win, COLOR_PAIR(proc->color));
}

void		color_pc(t_proc *proc, t_info *info, unsigned char *mem)
{
	static int		old_pc = 0;
	int				line;
	int				x;

	if (old_pc != -1)
	{
		uncolor_pc(proc, info, mem, old_pc);
		old_pc = proc->pc;;
	}
	line = proc->pc / 64;
	x = proc->pc;
	if (x > 64)
		x = x - (64 * line);
	x = x * 3;
	wattron(info->win, A_STANDOUT);
	wattron(info->win, COLOR_PAIR(proc->color));
	mvwprintw(info->win, line + 2, x + 2, conv_to_print(mem[proc->pc]));
	wrefresh(info->win);
	wattroff(info->win, COLOR_PAIR(proc->color));
	wattroff(info->win, A_STANDOUT);
}
