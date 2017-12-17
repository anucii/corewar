/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:43:20 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/17 23:57:33 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "judi.h"

static unsigned int lldi_calc(t_proc *proc, unsigned char *mem, int *param,\
		unsigned int (*p_idx)[3])
{
	unsigned int	ret;
	unsigned short	deref[2];
	ssize_t			i;

	i = -1;
	while (++i < 2)
	{
		if (param[i] == T_REG)
			deref[i] = proc->reg[mem[(*p_idx)[i]] - 1];
		else
			deref[i] = chars_to_short(mem, (*p_idx)[i]);
	}
	deref[0] = (proc->pc + deref[0] + deref[1]) % MEM_SIZE;
	return (ret = chars_to_int(mem, deref[0]));
}

void	f_lldi(t_proc **proc, unsigned char *mem)
{
	int				*param;
	unsigned int	p_idx[3];
	unsigned int	size;

	if (!(proc && *proc && mem))
		error_vm("f_lldi() called with undue null parameter(s)");
	param = checkocp(&mem[((*proc)->pc + 1) % MEM_SIZE]);
	size = 2 + param_size(((*proc)->pc + 2) % MEM_SIZE, param, 1, &p_idx);
	if (!parse_params(param, &p_idx, mem[(*proc)->pc % MEM_SIZE], mem))
	{
		execute_error(*proc);
		return ;
	}
	(*proc)->reg[mem[p_idx[2]] - 1] = lldi_calc(*proc, mem, param, &p_idx);
	(*proc)->pc = ((*proc)->pc + size) % MEM_SIZE;
	free(param);
}
