/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_aff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:44:25 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/13 13:58:08 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	print a character stocked in the reg passed in parameter apply %256 on it
*/

void	f_aff(t_proc **proc, unsigned char *mem)
{
	t_info			*info;
	int				*param;
	unsigned int	idx[3];
	unsigned int	i;

	info = get_info(NULL);
	param = checkocp(&mem[((*proc)->pc + 1) % MEM_SIZE], 16);
	i = param_size(((*proc)->pc + 2) % MEM_SIZE, param, 0, &idx);
	if (!parse_params(param, &idx, 16, mem))
		return (execute_error(*proc, param, i + 2));
	else
	{
		if (info && !info->opt[0])
			ft_printf("%c\n", (*proc)->reg[mem[idx[0]] - 1] % 256);
		(*proc)->pc = ((*proc)->pc + 3) % MEM_SIZE;
	}
	free(param);
}
