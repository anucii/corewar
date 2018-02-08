/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:43:20 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/08 12:31:46 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static unsigned int		lldi_calc(t_proc *proc, unsigned char *mem, int *param,\
		unsigned int (*p_idx)[3])
{
	int		ret;
	int		deref[2];
	ssize_t	i;

	i = -1;
	while (++i < 2)
	{
		if (param[i] == T_REG)
			deref[i] = proc->reg[mem[(*p_idx)[i]] - 1];
		else if (param[i] == T_IND)
			deref[i] = chars_to_short(mem, ((*p_idx)[i] \
					+ chars_to_short(mem, (*p_idx)[i], 1)), 1);
		else
			deref[i] = chars_to_short(mem, (*p_idx)[i], 1);
	}
	deref[0] = (proc->pc + deref[0] + deref[1]) % MEM_SIZE;
	return (ret = chars_to_int(mem, deref[0], 1));
}

void					f_lldi(t_proc **proc, unsigned char *mem)
{
	int				*param;
	unsigned int	p_idx[3];
	unsigned int	size;
	int				val;

	if (!(proc && *proc && mem))
		error_vm("f_lldi() called with undue null parameter(s)");
	param = checkocp(&mem[((*proc)->pc + 1) % MEM_SIZE], 14);
	size = 2 + param_size((*proc)->pc + 2, param, 1, &p_idx);
	if (!parse_params(param, &p_idx, 14, mem))
		return (execute_error(*proc, param, size));
	val = lldi_calc(*proc, mem, param, &p_idx);
	(*proc)->reg[mem[p_idx[2]] - 1] = val;
	(*proc)->carry = val ? 0 : 1;
	(*proc)->pc = ((*proc)->pc + size) % MEM_SIZE;
	free(param);
}
