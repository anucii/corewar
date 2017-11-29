/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ind_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:19:31 by jgonthie          #+#    #+#             */
/*   Updated: 2017/11/27 18:06:36 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

_Bool			ind_param(char **param, int *ty_param, char *s)
{
	if (s[0] == LABEL_CHAR && s[1])
	{
		if (!label_param(s))
			return (0);
	}
	else
	{
		if (!digit_param(s))
			return (0);
	}
	*param = ft_strsub(s, 0, ft_strlen(s));
	*ty_param = T_IND;
	return (1);
}
