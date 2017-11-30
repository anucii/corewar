/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_order_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:33:41 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/30 14:59:43 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Run at first to set the size of orders
**	(see write_order_pos for setting positions)
*/

 _Bool	dir_as_addr(char op_code)
{
	static const char	op_addr[] = {9, 10, 11, 12, 14, 15, -1};
	ssize_t				i;

	if ((op_code < 0) || (op_code > 16))
		exit(EXIT_FAILURE);
		//ft_error(1, "[ERR] : unvalid opcode");
	else if (!op_code)
		return (0);
	i = -1;
	while (op_addr[++i] != -1)
		if (op_code == op_addr[i])
			return (1);
	return (0);
}

