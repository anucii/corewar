/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:11:13 by jgonthie          #+#    #+#             */
/*   Updated: 2017/11/30 15:15:54 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		ft_cmpsting(char *s, int nb)
{
	int		tmp;

	tmp = ft_atoi(s);
	return (tmp - nb);
}

_Bool			reg_param(char **param, int *ty_param, char *s)
{
	char	value[3];
	int		index;
	int		index_val;

	index = 0;
	index_val = -1;
	ft_bzero(value, 3);
	if (s[index] != 'r' || ft_strlen(s) > 3)
		return (0);
	while (s[++index])
	{
		if (!ft_isdigit(s[index]))
			return (0);
		value[++index_val] = s[index];
	}
	if (ft_cmpsting(value, REG_NUMBER) > 0)
		return (0);
	*ty_param = T_REG;
	*param = ft_strsub(s, 1, ft_strlen(s) - 1);
	return (1);
}
