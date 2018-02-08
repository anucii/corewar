/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_zjmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:40:44 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/08 13:51:24 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**2 unsigned char transferred over 1 short to have the real number in case you
**wondering on the next formula, otherwise function who jump to adress
**passed % IDX_MOD
*/

void	f_zjmp(t_proc **proc, unsigned char *mem)
{
	short	i;
	t_info	*info;

	info = get_info(NULL);
	i = ((short)mem[((*proc)->pc + 1) % MEM_SIZE] << 8)
		| mem[((*proc)->pc + 2) % MEM_SIZE];
	if ((*proc)->carry == 1)
		(*proc)->pc = (((*proc)->pc + (i % IDX_MOD)) % MEM_SIZE);
	else
	{
		(*proc)->pc = (((*proc)->pc + 3) % MEM_SIZE);
		if (info->opt[3] && info->opt[4] && !info->opt[0])
			ft_printf(" [FAILED]");
	}
	return ;
}
