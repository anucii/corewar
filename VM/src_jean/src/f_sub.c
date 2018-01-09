/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_add.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:37:24 by jdaufin           #+#    #+#             */
/*   Updated: 2018/01/09 18:12:12 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

//WARNING operation modify carry

void	f_sub(t_proc **proc, unsigned char *mem)
{
	int				*param;
	unsigned int	idx[3];
	unsigned int	i;

	(void)mem;
	param = checkocp(&(*proc)->o_mem[1]);
	i = param_size(2, param, 1, &idx);
	//if (!parse_params(param, &idx, 4, mem)
	//	execute_error
	(*proc)->reg[(*proc)->o_mem[idx[2]] - 1] = (*proc)->reg[(*proc)->o_mem[idx[0]] - 1] -
		(*proc)->reg[(*proc)->o_mem[idx[1]] - 1];
	carry(&proc, (*proc)->reg[(*proc)->o_mem[idx[2]] - 1]);
	(*proc)->pc = ((*proc)->pc + i + 2) % MEM_SIZE;
	return ;
}

/* for test purpose
int		main(void)
{
	unsigned char mem[] = {4, 84, 1, 2, 3};
	t_proc		*p;

	p = ft_memalloc(sizeof(t_proc));
	p->reg[0] = 15;
	p->reg[1] = 16;
	p->reg[2] = 1;
	p->pc = 0;
	f_sub(&p, mem);
	ft_printf("pc = %hu\n, reg[2] = %u\n", p->pc, p->reg[2]);
	return(0);
}*/
