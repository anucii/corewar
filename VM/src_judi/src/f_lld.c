/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:42:56 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/26 15:47:14 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "judi.h"

static unsigned int	get_val(int p_type, unsigned char *mem, unsigned int pc,\
		unsigned int i)
{
	unsigned int	val;
	unsigned int	deref;

	if (p_type == T_DIR)
		val = chars_to_int(mem, i, 1);
	else
	{
		deref = (pc + (unsigned int)chars_to_short(mem, i, 1)) % MEM_SIZE;
		val = chars_to_int(mem, deref, 1);
	}
	return (val);
}

void				f_lld(t_proc **proc, unsigned char *mem)
{
	int				*param;
	unsigned int	p_idx[3];
	unsigned int	size;
	unsigned int	val;

	if (!(proc && *proc && mem))
		error_vm("f_lld : undue null parameter(s) received");
	param = checkocp(&mem[((*proc)->pc + 1) % MEM_SIZE]);
	if (!((param[0] & g_op_tab[12].tp_param[0])\
				&& (param[1] & g_op_tab[12].tp_param[1]) && (param[2] == 0)))
	{
		execute_error(*proc);
		return ;
	}
	size = 2 + param_size(((*proc)->pc + 2) % MEM_SIZE, param, 0, &p_idx);
	val = get_val(param[0], mem, (*proc)->pc, p_idx[0]);
	if ((!mem[p_idx[1]]) || (mem[p_idx[1]] > REG_NUMBER))
	{
		execute_error(*proc);
		return ;
	}
	(*proc)->reg[mem[p_idx[1]] - 1] = val;
	(*proc)->pc += size;
	free(param);
}
