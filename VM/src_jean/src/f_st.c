/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_st.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:36:53 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/20 15:10:10 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	f_st(t_proc **proc, unsigned char *mem)
{
	int				*i;
	unsigned short	s;

	i = checkocp(&mem[((*proc)->pc + 1) % MEM_SIZE]);
	//if (mem[((*proc)->pc + 2) % MEM_SIZE] > REG_NUMBER )
	//{
		//execute_error();
		//return ;
	//	}
	if (i[1] == T_REG)
	{/*
		if (mem[((*proc)->pc + 3) % MEM_SIZE] > REG_NUMBER)
		{
			execute_error();
			return ;
		}*/
		(*proc)->reg[mem[((*proc)->pc + 3) % MEM_SIZE] - 1] =
			(*proc)->reg[mem[((*proc)->pc + 2) % MEM_SIZE] - 1];
		(*proc)->pc = ((*proc)->pc + 4) % MEM_SIZE;
	}
	else
	{
		s = (short)mem[((*proc)->pc + 3) % MEM_SIZE] << 8
			| mem[((*proc)->pc + 4) % MEM_SIZE];
			int_on_mem(mem,
					(*proc)->reg[mem[((*proc)->pc + 2) % MEM_SIZE] - 1],
					(*proc)->pc + (s % IDX_MOD));
		(*proc)->pc = ((*proc)->pc + 5) % MEM_SIZE;
	}
	return ;
}

/*for quick test
int main(void)
{
	unsigned char mem[12] = {3, 96, 12, 0, 6, 1, 1, 1, 2, 2, 2 ,2};
	t_proc *p;

	p = ft_memalloc(sizeof(t_proc));
	p->pc = 0;
	p->reg[12] = 5413584;
	p->reg[1] = 1;
	f_st(&p, mem);
	int i = 0;
	while (i < 12)
	{
		ft_printf("%hhu\n", mem[i]);
		i++;
	}
	return (0);
}*/
