/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_fork.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:41:59 by jdaufin           #+#    #+#             */
/*   Updated: 2018/01/05 17:06:51 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	dbg_print_child(t_proc *child)
{
	t_info	*info;
	int		i;

	info = get_info(NULL);
	if (info->opt[0] || !info->opt[3])
		return ;
	i = -1;
	ft_printf("[NEWBORN (cy:%u)]: pid = %04u, pc = %04u, carry:%s\n",\
			global_timer(CHECK), child->pid, child->pc, child->carry ? "TRUE" \
			: "FALSE");
	ft_printf("> Registers:\n");
	while (++i < REG_NUMBER)
		ft_printf("[%d: %#04x(%u)]%c", i + 1, child->reg[i], child->reg[i],\
				(i + 1) % 8 ? ' ' : '\n');
	ft_printf("> Life status:\n");
	ft_printf(">> {%s, last_live: %u (life granted to player %d)}\n",\
			child->life.status ? "Alive" : "Dead", child->life.last,\
			child->life.player);
}

/*
**create a new processus at the adress given with % IDX_MOD
**inherit the status of is parent
*/

void	f_fork(t_proc **proc, unsigned char *mem)
{
	//unsigned short s;
	short	s;
	t_proc	*tmp;
	s = ((short)mem[(*proc)->pc + 1 % MEM_SIZE] << 8) |
		mem[((*proc)->pc + 2) % MEM_SIZE];
	tmp = (*proc);
	while(tmp->children != NULL)
		tmp = tmp->children;
	tmp->children = ft_memalloc(sizeof(t_proc));
	tmp->children = ft_memcpy(tmp->children, *proc, sizeof(t_proc));
	tmp->children->pc = (((*proc)->pc + (s  % IDX_MOD)) % MEM_SIZE);
	tmp->children->pid = get_pid(INCR);
	tmp->children->children = NULL;
	dbg_print_child(tmp->children);//dbg
	(*proc)->pc = ((*proc)->pc + 3) % MEM_SIZE;
	return ;
}
/*quick test// may need more test
int		main(void)
{
	t_proc *p = ft_memalloc(sizeof(t_proc));
	unsigned char mem[] = {12, 255, 0, 10};
	p->children = NULL;
	p->pc = 0;
	p->reg[4] = 4;
	f_fork(&p, mem);
	ft_printf("child = %u reg->child = %u\n father = %u\n", p->children->pc, p->children->reg[4], p->pc);
	return (0);
}*/
