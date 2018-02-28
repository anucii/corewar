/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:23:11 by jgonthie          #+#    #+#             */
/*   Updated: 2018/02/27 17:40:56 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		realloc_order(t_order ***order, int *size)
{
	int	start;
	int	end;

	start = *size * SIZE_STRUCT;
	end = start + SIZE_STRUCT;
	*size += 1;
	if ((*order = realloc(*order, sizeof(t_order *) *
					(*size * SIZE_STRUCT))) == NULL)
		error("[ERR] : Ft. Realloc Failed\n");
	while (start < end)
	{
		(*order)[start] = NULL;
		++start;
	}
}
