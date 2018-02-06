/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_aff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:44:25 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/06 14:17:10 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**print a character stocked in the reg passed in parameter apply %256 on it
*/

void	f_aff(t_proc **proc, unsigned char *mem)
{
	t_info			*info;
	int				*param;
	unsigned int	idx[3];
	unsigned int	i;

	info = get_info(NULL);
	param = checkocp(&mem[((*proc)->pc + 1) % MEM_SIZE], 16);
	i = param_size(((*proc)->pc + 2) % MEM_SIZE, param, 1, &idx);
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

/*quick test
int		main(void)
{
	t_proc *p;
	unsigned char mem[4] = {16, 1, 5, 89};

	p = ft_memalloc(sizeof(t_proc));
	p->pc = 0;
	p->reg[5] = 80;
	f_aff(&p, mem);
	return(0);
}*/
