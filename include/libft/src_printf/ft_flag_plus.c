/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:43:02 by jgonthie          #+#    #+#             */
/*   Updated: 2017/07/20 13:31:54 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_plus(t_spec *spec)
{
	char	*tmp;
	int		index;

	tmp = NULL;
	index = 0;
	if (spec->spc == 'u' || spec->spc == 'U' || spec->spc == 'c' ||
			spec->spc == 'C' || spec->spc == 'o' || spec->spc == 'O' ||
			spec->spc == 's' || spec->spc == 'p' || spec->spc == 'x' ||
			spec->spc == 'X' || ft_strchr(spec->spc_conv, '-'))
		return ;
	while (spec->spc_conv[index] == ' ')
		index++;
	if (index > 0)
	{
		spec->spc_conv[index - 1] = '+';
		return ;
	}
	if (spec->spc_conv[0] != '-')
	{
		tmp = ft_strdup(spec->spc_conv);
		ft_strdel(&spec->spc_conv);
		spec->spc_conv = ft_strjoin("+", tmp);
		ft_strdel(&tmp);
	}
}
