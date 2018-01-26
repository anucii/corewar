/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:37:55 by jgonthie          #+#    #+#             */
/*   Updated: 2018/01/26 18:13:51 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

_Bool			digit_param(char *s)
{
	int		index;

	index = 0;
	if (s[index + 1] == '-')
	{
		if (!s[index + 1])
			return (0);
		index++;
	}
	while (s[++index])
		if (!ft_isdigit(s[index]))
			return (0);
	return (1);
}

_Bool			label_param(char *s)
{
	int		index;
	int		len;

	index = 1;
	len = ft_strlen(s);
	while (++index < len)
		if (!ft_strchr(LABEL_CHARS, s[index]))
			return (0);
	return (1);
}
