/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sti.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:41:35 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/18 11:50:24 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/jordan.h"

void	f_sti(t_proc **proc, unsigned char *mem)
{
	unsigned short		s;
	unsigned short		t;
	unsigned int		i;
	int		*param;
	unsigned int		idx[3];


	param = checkocp(&mem[((*proc)->pc + 1) % MEM_SIZE]);
	i = param_size(((*proc)->pc + 2) % MEM_SIZE, param, 1, &idx);
	//if (mem[((*proc)->pc + 2) % MEM_SIZE] > 16)
	//	execute_error();
	if (param[1] == T_REG)
	{
		//if (mem[((*proc)->pc + 3) % MEM_SIZE] > 16)
		//	execute_error();
		s = (unsigned short)(*proc)->reg[mem[idx[1]] - 1];
	}
	else
		s = ((short)mem[idx[1]] << 8) |
			(mem[(idx[1] + 1)]);
	if (param[2] == T_REG)
		//if (mem[((*proc)->pc + 5) % MEM_SIZE] > 16)
		//	execute_error();
		t = (unsigned short)(*proc)->reg[mem[idx[2]] - 1];
	else
		t = mem[idx[2]] << 8 |
			mem[(idx[2] + 1)];
	int_on_mem(mem,
			(*proc)->reg[mem[((*proc)->pc + 2) % MEM_SIZE] - 1],
			(*proc)->pc + ((s + t) % IDX_MOD));
//	(*proc)->pc =
	return ;
}

int		main(void)
{
	unsigned char mem[12] = {11, 104, 12, 0, 4, 0, 4, 1, 2, 2, 2, 2};
	t_proc *p;

	p = ft_memalloc(sizeof(t_proc));
	p->pc = 0;
	p->reg[11] = 5413584;
	p->reg[0] = 1;
	p->reg[1] = 7;
	f_sti(&p, mem);
	int i = 0;
	while (i < 12)
	{
		ft_printf("%hhu\n", mem[i]);
		i++;
	}
	return (0);
}


