/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:24:23 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/23 20:10:46 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "judi.h"

_Bool	parse_instr(char **tokens, int max, t_order **slot)
{
	t_order *buf;

	if (!(tokens && *tokens && (max > 0) && slot && *slot))
	{
		ft_putendl_fd("[ERR] parse_instr : bad params", 2);
		exit(EXIT_FAILURE);
	}
	buf = *slot;
	/*
	 * moot operation for testing purposes
	 */
	buf->op_code = 42;
	return (1);
}
