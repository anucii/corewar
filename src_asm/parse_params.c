/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:29:28 by jdaufin           #+#    #+#             */
/*   Updated: 2018/01/26 14:53:02 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static _Bool	p_e(char *instr, int nb)
{
	ft_printf(RED"[%s] instr need [%d] params on line :\n", instr, nb);
	return (0);
}

static _Bool	ini_ty_param(t_op *tab, t_order *slot, char **param, int op_idx)
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
		slot->failure = ft_strdup(param[op_idx]);
		return (0);
	}
	return (1);
}

_Bool			pars_param(char **param, int max, t_order *slot, ssize_t op_idx)
{
	int			index;

	index = -1;
	while (++index < 16)
	{
		if (g_op_tab[index].op_code == slot->op_code)
		{
			slot->nb_param = g_op_tab[index].nb_param;
			slot->param = ft_memalloc(sizeof(char**) * slot->nb_param);
			if ((max - op_idx) != (g_op_tab[index].nb_param + 1))
				return (p_e(g_op_tab[index].name, g_op_tab[index].nb_param));
			if (!ini_ty_param(&g_op_tab[index], slot, param, op_idx))
			{
				index = -1;
				while (++index < slot->nb_param)
					if (slot->param[index])
						ft_strdel(&slot->param[index]);
				ft_memdel((void**)&slot->param);
				return (0);
			}
			return (1);
		}
	}
	return (1);
}
