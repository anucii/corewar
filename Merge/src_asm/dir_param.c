/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:11:40 by jgonthie          #+#    #+#             */
/*   Updated: 2017/11/30 15:15:21 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

_Bool			dir_param(char **param, int *ty_param, char *s)
{
	if (s[0] != '%' || !s[1])
		return (0);
	if (s[1] == LABEL_CHAR)
	{
		if (!label_param(s))
			return (0);
	}
	else
	{
		if (!digit_param(s))
			return (0);
	}
	*ty_param = T_DIR;
	*param = ft_strsub(s, 1, ft_strlen(s) - 1);
	return (1);
}
