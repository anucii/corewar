/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_order_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:33:41 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/04 16:50:57 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Run at first to set the size of orders
**	(see write_order_pos for setting positions)
*/

_Bool			dir_as_addr(char op_code)
{
	static const char	op_addr[] = {9, 10, 11, 12, 14, 15, -1};
	ssize_t				i;

	if ((op_code < 0) || (op_code > 16))
		error("[ERR] : unvalid opcode");
	else if (!op_code)
		return (0);
	i = -1;
	while (op_addr[++i] != -1)
		if (op_code == op_addr[i])
			return (1);
	return (0);
}

static short	get_param_size(char op_code, int ty_param)
{
	if (ty_param == T_REG)
		return (T_REG_SIZE);
	else if (ty_param == T_IND)
		return (T_IND_SIZE);
	else if (ty_param == T_DIR)
		return (dir_as_addr(op_code) ? T_IND_SIZE : T_DIR_SIZE);
	error("[ERR] : unvalid parameter type");
	return (0);
}

void			write_order_size(t_order *slot)
{
	short	buf;
	int		count[2];

	if (!slot)
		return ;
	buf = has_ocp(slot->op_code) ? 2 : 1;
	count[1] = slot->nb_param;
	count[0] = -1;
	while (++count[0] < count[1])
		buf += get_param_size(slot->op_code, slot->ty_param[count[0]]);
	slot->size = buf;
}
