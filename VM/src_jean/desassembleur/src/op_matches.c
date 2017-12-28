/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_matches.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 22:03:33 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/28 14:06:33 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crack.h"

char	op_matches(char *s)
{
	ssize_t	i;

	if (!s)
		return (-1);
	i = -1;
	while (g_op_tab[++i].op_code)
	{
		if (ft_atoi(s) == g_op_tab[i].op_code)
			return ((char)i);
	}
	return (-1);
}
