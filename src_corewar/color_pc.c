/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:22:25 by jgonthie          #+#    #+#             */
/*   Updated: 2018/02/27 18:47:19 by jgonthie         ###   ########.fr       */
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

static void	uncolor_pc(t_proc *proc, t_info *info, unsigned char *mem,\
		unsigned int old_pc)
{
	int				line;
	int				x;
	char			*s;

	line = old_pc / 64;
	x = old_pc;
	if (x >= 64)
		x = x - (64 * line);
	x = x * 3;
	mvwprintw(info->win, line + 2, x + 2, "  ");
	wattron(info->win, COLOR_PAIR(proc->color));
	mvwprintw(info->win, line + 2, x + 2, s = conv_to_print(mem[old_pc]));
	ft_strdel(&s);
}

void		color_pc(t_proc *proc, t_info *info, unsigned char *mem)
{
	int					line;
	int					x;
	char				*s;

	if (!info->opt[0])
		return ;
	uncolor_pc(proc, info, mem, proc->old_pc);
	line = proc->pc / 64;
	x = proc->pc;
	if (x >= 64)
		x = x - (64 * line);
	x = x * 3;
	wattron(info->win, A_STANDOUT);
	mvwprintw(info->win, line + 2, x + 2, s = conv_to_print(mem[proc->pc]));
	wattroff(info->win, COLOR_PAIR(proc->color));
	wattroff(info->win, A_STANDOUT);
	wrefresh(info->win);
	ft_strdel(&s);
	proc->old_pc = proc->pc;
}
