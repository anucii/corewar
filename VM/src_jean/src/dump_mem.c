/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 15:50:56 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/29 16:17:51 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	dump_mem(unsigned char *mem)
{
	ssize_t	i;

	if (!mem)
		return ;
	i = -1;
	while (++i < MEM_SIZE)
	{
		ft_printf("%hhx", mem[i]);
		if (!((i + 1) & 1))
			ft_printf("%c", (i + 1) % 32 ? ' ' : '\n');
	}
	if (MEM_SIZE & 1)
		ft_printf('\n');
}
