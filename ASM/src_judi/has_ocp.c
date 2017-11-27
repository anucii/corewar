/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_ocp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:49:17 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/27 16:57:28 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "judi.h"

_Bool	has_ocp(char op_code)
{
	ssize_t	i;

	i = -1
	while (g_op_tab[++i].name)
		if (g_op_tab[i].op_code == op_code)
			return (g_op_tab[i].has_ocp);
	exit(EXIT_FAILURE);
	//ft_error("[ERR] : non-referenced opcode");
}
