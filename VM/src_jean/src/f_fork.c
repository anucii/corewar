/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_fork.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:41:59 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/28 16:49:23 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/jordan.h"

/*
**create a new processus at the adress given with % IDX_MOD
**inherit the status of is parent
*/

void	f_fork(t_proc **proc, unsigned char *mem)
{
	unsigned short s;
	t_proc		*tmp;
	s = ((short)mem[(*proc)->pc + 1 % MEM_SIZE] << 8) |
		mem[((*proc)->pc + 2) % MEM_SIZE];
	tmp = (*proc);
	while(tmp->children != NULL)
		tmp = tmp->children;
	tmp->children = ft_memalloc(sizeof(t_proc));
	tmp->children = ft_memcpy(tmp->children, *proc, sizeof(t_proc));
	tmp->children->pc = (((*proc)->pc + (s  % IDX_MOD)) % MEM_SIZE);
	tmp->children->children = NULL;
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
