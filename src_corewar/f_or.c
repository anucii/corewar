/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_and.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:38:59 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/08 12:30:53 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	f_or(t_proc **proc, unsigned char *mem)
{
	int				*param;
	unsigned int	i;
	unsigned int	idx[3];
	int				j;
	int				s[2];

	j = 0;
	param = checkocp(&mem[((*proc)->pc + 1) % MEM_SIZE], 7);
	i = param_size(((*proc)->pc + 2) % MEM_SIZE, param, 0, &idx);
	if (!parse_params(param, &idx, 7, mem))
		return (execute_error(*proc, param, i + 2));
	while (j < 2)
	{
		if (param[j] == T_REG)
			s[j] = (*proc)->reg[mem[idx[j]] - 1];
		else if (param[j] == T_DIR)
			s[j] = convert(mem, idx[j], (*proc), 1);
		else if (param[j] == T_IND)
			s[j] = convert(mem, idx[j], (*proc), 0);
		j++;
	}
	(*proc)->reg[mem[idx[2]] - 1] = s[0] | s[1];
	carry(proc, (*proc)->reg[mem[idx[2]] - 1]);
	(*proc)->pc = ((*proc)->pc + i + 2) % MEM_SIZE;
	free(param);
}
