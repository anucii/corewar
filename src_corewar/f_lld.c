/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:42:56 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/08 12:30:00 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static unsigned int	get_val(int p_type, unsigned char *mem, t_proc *p,\
		unsigned int i)
{
	int	val;
	int	deref;

	if (p_type == T_DIR)
		val = chars_to_int(mem, i, 1);
	else
	{
		deref = (p->pc + (unsigned int)chars_to_short(mem, i, 1)) % MEM_SIZE;
		val = chars_to_short(mem, deref, 1);
		if (val > SHRT_MAX)
			val |= (USHRT_MAX << 16);
	}
	return (val);
}

void				f_lld(t_proc **proc, unsigned char *mem)
{
	int				*param;
	unsigned int	p_idx[3];
	unsigned int	size;
	int				val;

	if (!(proc && *proc && mem))
		error_vm("f_lld : undue null parameter(s) received");
	param = checkocp(&mem[((*proc)->pc + 1) % MEM_SIZE], 13);
	size = 2 + param_size(((*proc)->pc + 2) % MEM_SIZE, param, 0, &p_idx);
	if (!parse_params(param, &p_idx, 13, mem))
		return (execute_error(*proc, param, size));
	val = get_val(param[0], mem, (*proc), p_idx[0]);
	(*proc)->reg[mem[p_idx[1]] - 1] = val;
	(*proc)->carry = val ? 0 : 1;
	(*proc)->pc += size;
	free(param);
}
