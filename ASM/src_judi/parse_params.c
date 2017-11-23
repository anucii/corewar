/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:29:28 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/23 19:33:20 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "judi.h"

_Bool	parse_params(char **tokens, int max, t_order **slot)
{
	t_order *buf;

	if (!(tokens && *tokens && (max > 0) && slot && *slot))
	{
		ft_putendl_fd("[ERR] parse_params: bad params", 2);
		exit(EXIT_FAILURE);
	}
	buf = *slot;
	(buf->ty_param)[0] = T_DIR;
	(buf->ty_param)[1] = T_IND;
	(buf->ty_param)[2] = T_REG;
	return (1);
}
