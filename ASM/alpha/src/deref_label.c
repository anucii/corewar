/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deref_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:01:22 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/29 17:49:28 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Search label returns -1 if label doesn't fit, or the instruction's pos
**	otherwise
*/

static int	search_label(t_order *prog, char *label)
{
	char	**src;
	ssize_t	i;

	if (!(prog && label))
		error("[ERR] : search label bad params");
	src = prog->label;
	i = -1;
	while (src[++i])
	{
		if (ft_strequ(label, src[i]))
			return (prog->pos);
	}
	return (-1);
}

int			deref_label(t_order **prog, char *label)
{
	int	ret;
	int	i;

	if (!(prog && *prog && label))
		error("[ERR] dereferencing failure : no label or no program");
	ret = -1;
	i = 0;
	while (prog && prog[i]->label \
			&& ((ret = search_label(prog[i], label)) < 0))
		i++;
	return (ret);
}
