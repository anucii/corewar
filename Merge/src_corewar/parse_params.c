/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 19:51:45 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/20 19:01:41 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	This parsing function checks that the parameters types extracted from
**	the OCP (and stored in *param) fit with the operation definition.
**	More specifically, the function checks compatibility with an UNARY AND
**	and returns FALSE if the operation returns 0 AND the parameter type
**	tested is non-null.
**	It also checks that register indexes stored on the memory are within
**	the 1-to-REG_NUMBER range.
*/

_Bool		parse_params(int *param, unsigned int (*p_idx)[3],\
		unsigned char op_code, unsigned char *mem)
{
	ssize_t	i;
	ssize_t j;

	if (!(param && p_idx))
		error_vm("Void parameters indicators sent to parameters parser.");
	j = -1;
	while (++j < 17)
	{
		i = -1;
		if (op_code == g_op_tab[j].op_code)
		{
			while (++i < 3)
			{
				if ((param[i] == T_REG) && (!mem[(*p_idx)[i]] \
							|| (mem[(*p_idx)[i]] > REG_NUMBER)))
					return (0);
				if (!(g_op_tab[j].tp_param[i] & param[i]))
					if (param[i] || g_op_tab[j].tp_param[i])
						return (0);
			}
			return (1);
		}
	}
	return (0);
}
