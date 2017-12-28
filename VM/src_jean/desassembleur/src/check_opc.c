/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 18:45:20 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/28 11:14:00 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crack.h"

static _Bool	op_match(int (*size)[3], int instr, int nb_params)
{
	int		index;

	index = -1;
	while (++index < nb_params)
	{
		if (g_op_tab[instr].tp_param[index] & T_REG)
			if ((*size)[index] == REG_CODE)
				continue ;
		if (g_op_tab[instr].tp_param[index] & T_DIR)
			if ((*size)[index] == DIR_CODE)
				continue ;
		if (g_op_tab[instr].tp_param[index] & T_IND)
			if ((*size)[index] == IND_CODE)
				continue ;
		return (0);
	}
	return (1);
}

void		check_opc(int (*size)[3], char *opc, int instr, int nb_params)
{
	int		index;
	int		index_2;

	index = -1;
	index_2 = 0;
	while (++index < 3)
	{
		if (opc[index_2] == '0' && opc[index_2 + 1] == '1')
			(*size)[index] = REG_CODE;
		else if (opc[index_2] == '1' && opc[index_2 + 1] == '0')
			(*size)[index] = DIR_CODE;
		else if (opc[index_2] == '1' && opc[index_2 + 1] == '1')
			(*size)[index] = IND_CODE;
		else
			(*size)[index] = 0;
		index_2 += 2;
	}
	if (!op_match(size, instr, nb_params))
	{
		ft_printf("Error : Bad params for %s instr.", g_op_tab[instr].name);
		error(" Take only {DIR | IND, REG} params");
	}
}
