/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_on_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:48:15 by jpallard          #+#    #+#             */
/*   Updated: 2017/12/15 17:35:02 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/jordan.h"

void	int_on_mem(unsigned char *mem, unsigned int i)
{
	unsigned char	i1;
	unsigned char	i2;
	unsigned char	i3;

	i1 = i >> 24;
	i2 = i >> 16;
	i3 = i >> 8;
	ft_printf("i = %u, i1 = %hhu, i2 = %hhu, i3 = %hhu\n ",i, i1, i2, i3);
	mem[0] = i1;
	mem[1] = i2;
	mem[2] = i3;
	mem[3] = i;

	return ;
}
