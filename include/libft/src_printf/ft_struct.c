/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 17:04:47 by jgonthie          #+#    #+#             */
/*   Updated: 2017/07/20 13:35:43 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_inistruct(t_buff *buff, t_spec *spec)
{
	int		index;

	index = -1;
	buff->sentence = NULL;
	if (buff->len != -1)
		buff->check = 0;
	else
		buff->check = 1;
	buff->len = 0;
	buff->count = 1;
	spec->spc_conv = NULL;
	spec->spc = 0;
	spec->undefined = 0;
	while (index++ < 13)
		spec->tab_spec[index] = -1;
}

void		ft_resetstruct(t_spec *spec)
{
	int		index;

	index = -1;
	ft_strdel(&spec->spc_conv);
	spec->spc = 0;
	spec->undefined = 0;
	while (index++ < 13)
		spec->tab_spec[index] = -1;
}
