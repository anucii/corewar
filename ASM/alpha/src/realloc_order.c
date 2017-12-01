/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:23:11 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/01 14:46:37 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		realloc_order(t_order ****order, int *size)
{
	*size += 1;
	if ((**order = realloc(**order, sizeof(t_order *) *
					(*size * SIZE_STRUCT))) == NULL)
		error("[ERR] : Ft. Realloc Failed\n");
}
