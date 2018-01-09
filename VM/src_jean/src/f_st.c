/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_st.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:36:53 by jdaufin           #+#    #+#             */
/*   Updated: 2018/01/09 17:58:25 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	f_st(t_proc **proc, unsigned char *mem)
{
	int		*i;
	short	s;
	t_info	*info;

	i = checkocp(&(*proc)->o_mem[1]);
	if (i[1] == T_REG)
	{
		(*proc)->reg[(*proc)->o_mem[3] - 1] =
			(*proc)->reg[(*proc)->o_mem[2] - 1];
		(*proc)->pc = ((*proc)->pc + 4) % MEM_SIZE;
	}
	else
	{
		info = get_info(NULL);
		s = (short)(*proc)->o_mem[3] << 8
			| (*proc)->o_mem[4];
		int_on_mem(mem,
					(*proc)->reg[(*proc)->o_mem[2] - 1],
					(*proc)->pc + (s % IDX_MOD));
		info->start = (*proc)->pc + (s % IDX_MOD);
		info->end = info->start + 4;
		if (info && info->opt[0])
			refresh_arena(info, mem, (*proc)->color);
		(*proc)->pc = ((*proc)->pc + 5) % MEM_SIZE;
	}
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
