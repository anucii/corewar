/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_ld.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:36:05 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/15 14:53:37 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "judi.h"

void	f_ld(t_proc **proc, unsigned char *mem)
{
	int				*param;
	unsigned int	p_idx[3];
	unsigned int	size;
	int				val;

	if (!(proc && *proc && mem))
		error_vm("f_ld : undue null parameter(s) received");
	param = checkocp(&mem[((*proc)->pc + 1) % MEM_SIZE]);
	if (!((param[0] & g_op_tab[1].tp_param[0])\
				&& (param[1] & g_op_tab[1].tp_param[1]) \
				&& (param[2] == 0)))
	{
		execute_error(*proc);
		return ;
	}
	size = 2 + param_size(((*proc)->pc + 2) % MEM_SIZE, param, 0, &p_idx);
	val = get_val();
	if (mem[p_idx[1]] >= REG_NUMBER)
		execute_error(*proc);
	(*proc)->pc += size;
	free(param);
}
