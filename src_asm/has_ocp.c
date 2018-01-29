/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_ocp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:49:17 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/30 18:19:44 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

_Bool	has_ocp(char op_code)
{
	ssize_t	i;

	i = -1;
	while (g_op_tab[++i].name)
		if (g_op_tab[i].op_code == op_code)
			return (g_op_tab[i].has_ocp);
	error("[ERR] : non-referenced opcode");
	return (0);
}
