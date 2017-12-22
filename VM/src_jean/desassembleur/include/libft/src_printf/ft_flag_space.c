/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:53:33 by jgonthie          #+#    #+#             */
/*   Updated: 2017/07/20 13:32:04 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_space(t_spec *spec)
{
	char	*tmp;
	int		len;
	int		index;

	tmp = NULL;
	index = 0;
	len = ft_strlen(spec->spc_conv);
	if (spec->tab_spec[2] >= 0 || len <= 1 || spec->tab_spec[3] > 0
			|| spec->spc == 'u' || spec->spc == 'U' || spec->spc == 's'
			|| spec->spc == 'S' || spec->spc == 'p' || spec->spc == 'o'
			|| spec->spc == 'x' || spec->spc == 'X')
		return ;
	if (spec->tab_spec[1] != len && spec->spc_conv[0] != '-')
	{
		tmp = ft_strnew(len + 1);
		tmp[0] = ' ';
		while (spec->spc_conv[index])
		{
			tmp[index + 1] = spec->spc_conv[index];
			index++;
		}
		ft_strdel(&spec->spc_conv);
		spec->spc_conv = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
}
