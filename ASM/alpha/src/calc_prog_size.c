/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_prog_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:45:24 by jpallard          #+#    #+#             */
/*   Updated: 2017/11/29 14:55:18 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		calc_prog_size(t_order **champ, t_header *hdr)
{
	unsigned int	i;
	unsigned int	size;

	i = 0;
	size = 0;
	while (i < hdr->nb_struct)
	{
		size = size + champ[i]->pos;
		i++;
	}
	hdr->prog_size = size;
}
