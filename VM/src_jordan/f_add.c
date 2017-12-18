/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_add.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:37:24 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/18 13:23:31 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/jordan.h"

//WARNING operation modify carry

void	f_add(t_proc **proc, unsigned char *mem)
{
	int				*param;
	unsigned int	idx[3];
	unsigned int	i;

	param = checkocp(&mem[((*proc)->pc + 1) % MEM_SIZE]);
	i = param_size(((*proc)->pc + 2) % MEM_SIZE, param, 1, &idx);
	//if (!parse_params(param, &idx, 4, mem)
	//	execute_error
	(*proc)->reg[mem[idx[2] - 1]] = (*proc)->reg[mem[idx[0]] - 1] +
		(*proc)->reg[mem[idx[1]] - 1];
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
	p->reg[1] = 15;
	p->reg[2] = 1;
	p->pc = 0;
	f_add(&p, mem);
	ft_printf("pc = %hu\n, reg[2] = %u\n", p->pc, p->reg[2]);
	return(0);
}*/
