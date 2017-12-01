/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:29:28 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/27 19:00:50 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "JEAAAAAAAAAAAAN.h"

static _Bool	ini_ty_param(t_op *tab, t_order *slot, char **param, int op_idx)
{
	int		index;

	index = -1;
	while (++index < slot->nb_param)
	{
		op_idx++;
	//	ft_putstr("LOOP\n");
		if (tab->tp_param[index] & T_REG)
			if (reg_param(&slot->param[index], &slot->ty_param[index], param[op_idx]))
			{
			//	ft_printf("param[i]: %s, ty_param[i]: %d\n", slot->param[index], slot->ty_param[index]);
				continue ;
			}
		if (tab->tp_param[index] & T_DIR)
			if (dir_param(&slot->param[index], &slot->ty_param[index], param[op_idx]))
			{
			//	ft_printf("param[i]: %s, ty_param[i]: %d\n", slot->param[index], slot->ty_param[index]);
				continue ;
			}
		if (tab->tp_param[index] & T_IND)
			if (ind_param(&slot->param[index], &slot->ty_param[index], param[op_idx]))
			{
			//	ft_printf("param[i]: %s, ty_param[i]: %d\n", slot->param[index], slot->ty_param[index]);
				continue ;
			}
		ft_putstr("ERROR|\n");
		return (0);
	}
	ft_putstr("Next line\n");
	return (1);
}

_Bool			parse_params(char **tokens, int max, t_order *slot, ssize_t op_idx)
{
	int			index;

	index = -1;
	while (++index < REG_NUMBER)
	{
		if (g_op_tab[index].op_code == slot->op_code)
		{
			slot->nb_param = g_op_tab[index].nb_param;
		//	ft_printf("nb_param : %d\n", slot->nb_param);
			slot->param = ft_memalloc(sizeof(char**) * slot->nb_param);
		//	ft_printf("%d -- %d\n", max, (op_idx + g_op_tab[index].nb_param));
			/*if (max <= op_idx + g_op_tab[index].nb_param)
			{
				ft_putstr("test return\n");
				return (0);
			}*/
			if (!ini_ty_param(&g_op_tab[index], slot, tokens, op_idx))
			{
				index = -1;
				while (++index < slot->nb_param)
					if (slot->param[index])
						ft_strdel(&slot->param[index]);
				ft_memdel((void**)slot->param);
				return (0);
			}
		//	return (1);
		}
	}
	return (1);
	ft_printf("%d\n", max);
}
