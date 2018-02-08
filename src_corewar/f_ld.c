/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_ld.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:36:05 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/08 13:50:32 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	get_val() is called only if the first parameter is well typed, so the
**	alternative is between T_DIR and T_IND, the indirect parameter is handled
**	within the else statement
*/

static unsigned int	get_val(int p_type, unsigned char *mem, t_proc *p,\
		unsigned int i)
{
	unsigned int	val;
	unsigned int	deref;

	if (p_type == T_DIR)
		val = chars_to_int(mem, i, 1);
	else
	{
		deref = (p->pc + (chars_to_short(mem, i, 1) % IDX_MOD))\
				% MEM_SIZE;
		val = chars_to_int(mem, deref, 1);
	}
	return (val);
}

/*
**	f_ld() checks the fitness between the types stored in the OCP and the
**	ld instruction prototype (see g_op_tab[]) and then operates.
**	NB : no need to call a modulo MEM_SIZE on the values stored in p_idx[],
**	the job of taking this constraint into account is done by the param_size()
**	function.
*/

void				f_ld(t_proc **proc, unsigned char *mem)
{
	int				*param;
	unsigned int	p_idx[3];
	unsigned int	size;
	int				val;

	if (!(proc && *proc && mem))
		error_vm("f_ld : undue null parameter(s) received");
	param = checkocp(&mem[((*proc)->pc + 1) % MEM_SIZE], 2);
	size = 2 + param_size(((*proc)->pc + 2) % MEM_SIZE, param, 0, &p_idx);
	if (!parse_params(param, &p_idx, 2, mem))
		return (execute_error(*proc, param, size));
	val = get_val(param[0], mem, (*proc), p_idx[0]);
	(*proc)->reg[mem[p_idx[1]] - 1] = val;
	(*proc)->carry = val ? 0 : 1;
	(*proc)->pc += size;
	free(param);
}
