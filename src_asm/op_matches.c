/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_matches.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 22:03:33 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/24 18:19:58 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	op_matches(char *s)
{
	ssize_t	i;

	if (!s)
		return (-1);
	i = -1;
	while (g_op_tab[++i].name)
	{
		if (ft_strequ(s, g_op_tab[i].name))
			return ((char)i);
	}
	return (-1);
}
