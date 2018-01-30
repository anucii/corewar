/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:13:34 by jpallard          #+#    #+#             */
/*   Updated: 2018/01/30 18:16:27 by jdaufin          ###   ########.fr       */
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
	while (i < 16)
	{
		if (mem[p->pc] == g_op_tab[i].op_code || p->c_opc != -1)
		{
			if (p->cc == 0)
				p->c_opc = i;
			if (++(p->cc) == g_op_tab[p->c_opc].cycles)
			{
				if (info->opt[3] && info->opt[4] && !info->opt[0])
					ft_printf("[EXEC (cy:%04u)]: %s (proc:%04u, pc:%04u,  \
player:%d)", global_timer(CHECK), g_op_tab[p->c_opc].description, p->pid, p->pc,\
p->champ.id);
				p->cc = 0;
				g_op_tab[p->c_opc].func(&p, mem);
				p->c_opc = -1;
				if (info->opt[3] && info->opt[4] && !info->opt[0])
					ft_printf(" new_pc:%04u \n", p->pc);
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
<<<<<<< HEAD
**	exec_wrapper() enables the handling of the execution of children
**	processes when needed; its new version uses a general list (common to 
**	all players) of the processes adresses.
=======
**	exec_wrapper() enables the handling of the execution of next
**	processes when needed.
>>>>>>> db57eea64e3e
*/

void	exec_wrapper(unsigned char *mem, t_proc *p)
{
	t_proc		*tmp;

	tmp = p;
	while (tmp)
	{
		execute_order(mem, tmp);
		tmp = tmp->next;
	}/*
	while (p->next)
		exec_wrapper(mem, p->next);*/
}

static _Bool	new_round(t_proc **p, t_info *info, _Bool *c)
{
	print_board(p, info);
	atropos(p);
	timer(REINIT);
	*c = (*p != NULL);
	deadline(DECR);
	foreach_proc(p, &reinit_life_status);
	return (*c);
}

/*
**	The run function manages the cycles, it stops only when there is no
**	more processus alive.
*/

void			run(unsigned char *mem, t_proc **p)
{
	_Bool	c;
	t_info	*info;

	if (!(mem && p))
		return ;
	c = 1;
	info = get_info(NULL);
	while (1)
	{
		exec_wrapper(mem, *p);
		print_board(p, info);
		if (!c || dump_mem(mem))
			return ;
		if (timer(CHECK) >= deadline(CHECK))
			new_round(p, info, &c);
		timer(INCR);
		if (info->opt[0])
			if (!ctrl_speed(info))
				return ;
	}
}