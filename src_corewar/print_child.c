/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:21:39 by jdaufin           #+#    #+#             */
/*   Updated: 2018/01/30 17:51:03 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_child(t_proc *child)
{
	t_info	*info;
	int		i;

	info = get_info(NULL);
	if (info->opt[0] || !info->opt[3] || !info->opt[4])
		return ;
	i = -1;
	ft_printf("\n[NEWBORN (cy:%u)]: player %s(no %d), pid = %04u, pc = %04u, \
carry:%s\n", global_timer(CHECK), child->champ.name, child->champ.id,\
child->pid, child->pc, child->carry ? "TRUE" : "FALSE");
	ft_printf("> Registers:\n");
	while (++i < REG_NUMBER)
		ft_printf("[%d: 0x%08x(%d)]%c", i + 1, child->reg[i], child->reg[i],\
				(i + 1) % 8 ? ' ' : '\n');
	ft_printf("> Life status:\n");
	ft_printf(">> {%s, last_live: %u (life granted to player %d)}\n",\
			child->life.status ? "Alive" : "Dead", child->life.last,\
			child->life.player);
}
