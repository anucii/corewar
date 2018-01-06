/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_on_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:48:15 by jpallard          #+#    #+#             */
/*   Updated: 2018/01/06 14:07:36 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	int_on_mem(unsigned char *mem, unsigned int i, unsigned short s)
{
	unsigned char	i1;
	unsigned char	i2;
	unsigned char	i3;

	i1 = i >> 24;
	i2 = i >> 16;
	i3 = i >> 8;
	mem[s % MEM_SIZE] = i1;
	mem[(s + 1) % MEM_SIZE] = i2;
	mem[(s + 2) % MEM_SIZE] = i3;
	mem[(s + 3) % MEM_SIZE] = i;
	return ;
}
