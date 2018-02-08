/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_and.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:38:59 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/08 12:16:24 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

unsigned int	convert(unsigned char *mem, unsigned int idx, t_proc *proc,\
		int j)
{
	unsigned int	o;
	unsigned short	s;

	o = 0;
	if (j == 1)
		o = ((unsigned int)mem[idx] << 24) |
			((unsigned int)mem[idx + 1] << 16) |
			((unsigned int)mem[idx + 2] << 8) |
			(mem[idx + 3]);
	else if (j == 0)
	{
		s = (mem[idx] << 8) | (mem[idx + 1]);
		s %= MEM_SIZE;
		o = (mem[(proc->pc + s) % MEM_SIZE]) << 24;
		o |= (mem[(proc->pc + s + 1) % MEM_SIZE]) << 16;
		o |= (mem[(proc->pc + s + 2) % MEM_SIZE]) << 8;
		o |= (mem[(proc->pc + s + 3) % MEM_SIZE]);
	}
	return (o);
}
