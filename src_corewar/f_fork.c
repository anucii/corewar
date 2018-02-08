/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_fork.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:41:59 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/08 14:17:24 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	create a new processus at the adress given with % IDX_MOD
**	inherit the status of is parent
*/

void	f_fork(t_proc **proc, unsigned char *mem)
{
	short	s;
	t_proc	*tmp;

	s = ((short)mem[((*proc)->pc + 1) % MEM_SIZE] << 8) |
		mem[((*proc)->pc + 2) % MEM_SIZE];
	tmp = proc_dup(proc_hdr(CHECK), *proc);
	tmp->pc = (((*proc)->pc + (s % IDX_MOD)) % MEM_SIZE);
	tmp->pid = get_pid(INCR);
	tmp->c_opc = -1;
	print_child(tmp);
	(*proc)->pc = ((*proc)->pc + 3) % MEM_SIZE;
	return ;
}
