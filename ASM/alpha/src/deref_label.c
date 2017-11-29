/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deref_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:01:22 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/29 15:05:58 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	search_label(t_order *prog, char *label)
{
	char	**src;

	if (!(prog && label))
		return (-1);
	src = prog->label;
	while (src)
	{
		if (ft_strequ(label, *src))
			return (prog->pos);
		src++;
	}
	return (-1);
}

int			deref_label(t_order **prog, char *label)
{
	int	ret;
	int	i;

	if (!(prog && *prog && label))
	{
		//ft_error(1, "[ERR] dereferencing failure : no label or no program");
		exit(EXIT_FAILURE);
	}
	ret = -1;
	i = -1;
	while (prog && prog[++i]->label && ((ret = search_label(prog[i], label)) < 0))
		;
	return (ret);
}
