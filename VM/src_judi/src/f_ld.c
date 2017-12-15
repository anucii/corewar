/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_ld.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:36:05 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/15 15:59:04 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "judi.h"

/*
**	get_val() is called only if the first parameter is well typed, so the 
**	alternative is between T_DIR and T_IND, the indirect parameter is handled
**	within the else statement
*/

static int	get_val(int p_type, unsigned char *mem, unsigned int i)
{
	int				val;
	unsigned int	deref;

	if (p_type == T_DIR)
		val = chars_to_int(mem, i);
	else
	{
		deref = (unsigned int)(chars_to_short(mem, i) % IDX_MOD);
		val = (int)chars_to_int(mem, deref);
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
				&& (param[1] & g_op_tab[1].tp_param[1]) && (param[2] == 0)))
	{
		execute_error(*proc);
		return ;
	}
	size = 2 + param_size(((*proc)->pc + 2) % MEM_SIZE, param, 0, &p_idx);
	val = get_val(param[0], mem, p_idx[0]);
	if (mem[p_idx[1]] >= REG_NUMBER)
	{
		execute_error(*proc);
		return ;
	}
	reg[mem[p_idx[1]]] = val;
	(*proc)->pc += size;
	free(param);
}
