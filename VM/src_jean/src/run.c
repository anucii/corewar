/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:13:34 by jpallard          #+#    #+#             */
/*   Updated: 2018/01/05 16:08:43 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static _Bool	ctrl_speed(t_info *info)
{
	static int	speed = 50000;
	char		ch;

	timeout(1);
	usleep(speed);
	ch = getch();
	if (ch == 'w' && speed > 0)
		speed -= 10000;
	if (ch == 'e' && speed < 70000)
		speed += 10000;
	if (ch == 'Q')
	{
		destroy_win(info);
		endwin();
		return (0);
	}
	return (1);
}

/*
**	execute_order() checks that the process has been called on enough cycles
**	and then calls the operation execution function associated with the opcode
*/

void	execute_order(unsigned char *mem, t_proc *p)
{
	int		i;
	t_info	*info;

	i = 0;
	info = get_info(NULL);
	while (mem[p->pc] && (i < 17))
	{
		if (mem[p->pc] == g_op_tab[i].op_code)
		{
			if (++(p->cc) == (unsigned int)g_op_tab[i].cycles)
			{
				if (info->opt[3] && !info->opt[0])
					ft_printf("[EXEC (cy:%04u)]: %s (proc:%04u, pc:%04u,  \
player:%d)\n", global_timer(CHECK), g_op_tab[i].description, p->pid, p->pc,\
p->champ.id);
				p->cc = 0;
				g_op_tab[i].func(&p, mem);
			}
			color_pc(p, info, mem);
			return ;
		}
		i++;
	}
	p->pc++;
	p->pc %= MEM_SIZE;
}

/*
**	exec_wrapper() enables the handling of the execution of children
**	processes when needed.
*/

void	exec_wrapper(unsigned char *mem, t_proc *p)
{
	//t_proc	*tmp;


	if (p->children)
		exec_wrapper(mem, p->children);
	execute_order(mem, p);
	/*
	tmp = p;
	while (tmp)
	{
		execute_order(mem, tmp);
		tmp = tmp->children;
	}
	*/
}

/*
**	The run function manages the cycles, it stops only when there is no
**	more processus alive.
*/

void	run(unsigned char *mem, t_proc **p)
{
	_Bool	c;
	ssize_t	i;
	t_info	*info;

	if (!(mem && p))
		return ;
	c = 1;
	info = get_info(NULL);
	while (c)
	{
		while (timer(CHECK) < deadline(CHECK))
		{
			i = (ssize_t)info->nb_player;
			while (--i >= 0)
				if (p[i])
					exec_wrapper(mem, p[i]);
			timer(INCR);
		if (info->opt[0])
			if (!ctrl_speed(info))
				return ;
		}
		c = 0;
		atropos(p, info->nb_player);
		timer(REINIT);
		while (++i < (ssize_t)info->nb_player)
			c |= p[i] ? 1 : 0;
		deadline(DECR);
		foreach_proc(p, info->nb_player, &reinit_life_status);
	}
}
