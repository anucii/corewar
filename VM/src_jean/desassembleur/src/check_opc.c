/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 18:45:20 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/27 20:02:06 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crack.h"

static _Bool	op_match(int (*size)[3], int instr)
{
	int		index;

	index = -1;
	while (++index < slot->nb_param)
	{
		op_idx++;
		if (tab->tp_param[index] & T_REG)
			if (reg_param(&slot->param[index], &slot->ty_param[index], \
						param[op_idx]))
				continue ;
		if (tab->tp_param[index] & T_DIR)
			if (dir_param(&slot->param[index], &slot->ty_param[index], \
						param[op_idx]))
				continue ;
		if (tab->tp_param[index] & T_IND)
			if (ind_param(&slot->param[index], &slot->ty_param[index], \
						param[op_idx]))
				continue ;
		return (0);
	}
	return (1);
}

void		check_opc(int (*size)[3], char *opc, int instr)
{
	int		index;
	int		index_2;

	index = -1;
	index_2 = 0;
	while (++index < 3)
	{
		ft_printf("opc[index] : %c%c\n", opc[index_2], opc[index_2 + 1]);
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
	if (!op_match(size, instr))
	{
		ft_printf("Bad params for %s instr\n", g_op_tab);
		error("");
	}
}
