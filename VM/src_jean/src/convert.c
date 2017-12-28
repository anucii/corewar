/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_and.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:38:59 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/26 16:56:53 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/jordan.h"

unsigned int	convert(unsigned char *mem, unsigned int idx, unsigned short pc, int j)
{
	unsigned int	o;

	o = 0;
	if (j == 1)
		o = ((unsigned int)mem[idx] << 24) |
			((unsigned int)mem[idx + 1] << 16) |
			((unsigned int)mem[idx + 2] << 8) |
			(mem[idx + 3]);
	else if (j == 0)
	{
		o = (((unsigned short)mem[idx] << 8) | (mem[idx + 1])) % IDX_MOD;
		o = ((unsigned int)mem[(pc + o) % MEM_SIZE]) << 24 |
			((unsigned int)mem[(pc + o + 1) % MEM_SIZE]) << 16 |
			((unsigned int)mem[(pc + o + 2) % MEM_SIZE]) << 8 |
			(mem[pc + o + 3]) % MEM_SIZE;
	}
	return (o);
}
