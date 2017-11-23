/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_matches.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 22:03:33 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/23 22:46:41 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "judi.h"

_Bool	op_matches(char *s)
{
	ssize_t	i;

	if (!s)
		return (0);
	i = -1;
	while (g_op_tab[++i].name)
	{
		if (ft_strequ(s, g_op_tab[i].name))
			return (1);
	}
	return (0);
}
