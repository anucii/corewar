/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_st.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:36:53 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/14 15:03:20 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	addr_on_reg(t_proc *proc, unsigned char *mem, t_info *info, \
		unsigned int (*idx)[3])
{
	proc->reg[mem[(*idx)[1]] - 1] = proc->reg[mem[(*idx)[0]] - 1];
	info = get_info(NULL);
	if (info->opt[3] && info->opt[4] && !info->opt[0])
		ft_printf("\n\t\t\tstore %d(from r[%d]) @r[%d]",\
				proc->reg[mem[(*idx)[0]] - 1], mem[(*idx)[1] - 1],\
				proc->reg[mem[(*idx)[1] - 1]]);
	proc->pc = (proc->pc + 4) % MEM_SIZE;
}

static void	addr_on_ind(t_proc *proc, unsigned char *mem, t_info *info, \
		unsigned int (*idx)[3])
{
	short	s;

	s = (short)mem[(proc->pc + 3) % MEM_SIZE] << 8
		| mem[(proc->pc + 4) % MEM_SIZE];
	int_on_mem(mem, proc->reg[mem[(*idx)[0]] - 1], proc->pc + (s % IDX_MOD));
	info->start = (proc->pc + (s % IDX_MOD)) % MEM_SIZE;
	info->end = (info->start + 4) % MEM_SIZE;
	if (info->opt[0])
		refresh_arena(info, mem, proc->color);
	proc->pc = (proc->pc + 5) % MEM_SIZE;
}

void		f_st(t_proc **proc, unsigned char *mem)
{
	int				*param;
	int				size;
	unsigned int	idx[3];

	param = checkocp(&mem[((*proc)->pc + 1) % MEM_SIZE], 3);
	size = param_size(((*proc)->pc + 2) % MEM_SIZE, param, 0, &idx) + 2;
	if (!parse_params(param, &idx, 3, mem))
		return (execute_error(*proc, param, size));
	if (param[1] == T_REG)
		addr_on_reg(*proc, mem, get_info(NULL), &idx);
	else
		addr_on_ind(*proc, mem, get_info(NULL), &idx);
	free(param);
}
