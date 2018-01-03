/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:13:34 by jpallard          #+#    #+#             */
/*   Updated: 2018/01/03 17:17:31 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	execute_order() checks that the process has been called on enough cycles
**	and then calls the operation execution function associated with the opcode
*/

void	execute_order(unsigned char *mem, t_proc *p)
{
	int		i;

	i = 0;
	while (mem[p->pc] && (i < 17))
	{
		if (mem[p->pc] == g_op_tab[i].op_code)
		{
			if (++(p->cc) == (unsigned int)g_op_tab[i].cycles)
			{
				//dbg messages
//				ft_printf("Proc no %u, pc = %u\n, instruction : %s\n",\
//				 	  p->pid, p->pc, g_op_tab[i].description);
				g_op_tab[i].func(&p, mem);
				p->cc = 0;
			}
			return ;
		}
		i++;
	}
	p->pc++;
	p->pc %= MEM_SIZE;
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
					execute_order(mem, p[i]);
			if (info->opt[0])
				usleep(50000);
			timer(INCR);
		}
		timer(REINIT);
		c = 0;
		atropos(p, info->nb_player);
		while (++i < (ssize_t)info->nb_player)
			c |= p[i] ? 1 : 0;
		deadline(DECR);
		foreach_proc(p, info->nb_player, &reinit_life_status);
	}
}
