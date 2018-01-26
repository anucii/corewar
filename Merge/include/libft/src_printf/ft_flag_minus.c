/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:43:49 by jgonthie          #+#    #+#             */
/*   Updated: 2017/07/20 13:31:47 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putspace(t_spec *spec, char *tmp, int index)
{
	if (ft_strchr(spec->spc_conv, '-') && spec->tab_spec[3] > 0)
		spec->tab_spec[1] += 1;
	while (index <= spec->tab_spec[1] - 1)
	{
		tmp[index] = ' ';
		index++;
	}
	ft_strdel(&spec->spc_conv);
	spec->spc_conv = ft_strdup(tmp);
	ft_strdel(&tmp);
}

void		ft_minus(t_spec *spec)
{
	char		*tmp;
	int			len_spec;
	int			index;

	tmp = NULL;
	len_spec = ft_strlen(spec->spc_conv);
	index = 0;
	if (spec->tab_spec[1] > len_spec)
	{
		tmp = ft_strnew(spec->tab_spec[1] + 1);
		while (index < len_spec)
		{
			tmp[index] = spec->spc_conv[index];
			index++;
		}
		ft_putspace(spec, tmp, index);
		len_spec = ft_strlen(spec->spc_conv);
		if (spec->tab_spec[2] > 0 && spec->spc_conv[len_spec - 1] == ' '
				&& spec->tab_spec[3] > 0)
			spec->spc_conv[len_spec - 1] = '\0';
	}
}
