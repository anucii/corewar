/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deref_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:01:22 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/30 19:36:31 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Search label returns -1 if label doesn't fit, or the instruction's pos
**	otherwise
*/
/*
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
*/

static int	search_label(t_order *prog, char *label)
{
	int		index;

	if (!(prog && label))
		error("[ERR] : search label bad params");
	index = -1;
	while (++index < prog->nb_label)
	{
		if (ft_strequ(label, prog->label[index]))
			return (prog->pos);
	}
	return (-1);
}

int			deref_label(t_order **prog, char *label)
{
	int	ret;
	int	i;

	ret = -1;
	i = 0;
	if (!(prog && *prog && label))
		error("[ERR] dereferencing failure : no label or no program");
	while (prog && prog[i] && prog[i]->label && ((ret = search_label(prog[i], label)) < 0))
		i++;
//	ft_printf("ret : %d\n", ret);
	return (ret);
}
