/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_to_short.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:20:26 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/08 12:10:44 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	See chars_to_int.c for an explanation of the underlying logic
*/

short	chars_to_short(unsigned char *mem, unsigned int i, _Bool lg)
{
	short			val;
	unsigned int	mod;

	if (!mem)
		error_vm("chars_to_short() called with a null memory pointer");
	mod = lg ? MEM_SIZE : IDX_MOD;
	val = ((short)mem[i % mod] << 8) \
		| ((short)mem[(i + 1) % mod]);
	return (val);
}
