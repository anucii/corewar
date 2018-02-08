/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_add.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:37:24 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/08 12:19:24 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	WARNING operation modifies carry
*/

void	f_add(t_proc **proc, unsigned char *mem)
{
	int				*param;
	unsigned int	idx[3];
	unsigned int	i;

	param = checkocp(&mem[((*proc)->pc + 1) % MEM_SIZE], 4);
	i = param_size(((*proc)->pc + 2) % MEM_SIZE, param, 0, &idx);
	if (!parse_params(param, &idx, 4, mem))
		return (execute_error(*proc, param, i + 2));
	(*proc)->reg[mem[idx[2]] - 1] = (*proc)->reg[mem[idx[0]] - 1] +
		(*proc)->reg[mem[idx[1]] - 1];
	carry(proc, (*proc)->reg[mem[idx[2]] - 1]);
	(*proc)->pc = ((*proc)->pc + i + 2) % MEM_SIZE;
	free(param);
}
