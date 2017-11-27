/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deref_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:01:22 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/27 13:42:47 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/jordan.h"

static int	search_label(t_order **prog, char *label)
{
	char	**src;

	if (!(prog && *prog && label))
		return (-1);
	src = (*prog)->label;
	while (src)
	{
		if (ft_strequ(label, *src))
			return ((*prog)->pos);
		src++;
	}
	return (-1);
}

int			deref_label(t_order **prog, char *label)
{
	int	ret;

	if (!(prog && *prog && label))
	{
		//ft_error(1, "[ERR] dereferencing failure : no label or no program");
		exit(EXIT_FAILURE);
	}
	ret = -1;
	while (prog && *prog && ((ret = search_label(prog, label)) < 0))
		prog = &(prog[1]);
	return (ret);
}
