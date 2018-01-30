/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_st.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:36:53 by jdaufin           #+#    #+#             */
/*   Updated: 2018/01/30 17:46:04 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	f_st(t_proc **proc, unsigned char *mem)
{
	int				*param;
	short			s;
	int				size;
	unsigned int	idx[3];
	t_info			*info;

	param = checkocp(&mem[((*proc)->pc + 1) % MEM_SIZE], 3);
	size = param_size(((*proc)->pc + 2) % MEM_SIZE, param, 1, &idx) + 2;
	if (!parse_params(param, &idx, 3, mem))
		return (execute_error(*proc, param, size));
	if (param[1] == T_REG)
	{
		(*proc)->reg[mem[idx[1]] - 1] =
			(*proc)->reg[mem[idx[0]] - 1];
		info = get_info(NULL);
		if (info->opt[3] && info->opt[4] && !info->opt[0])
			ft_printf("\n\t\t\tstore %d(from r[%d]) @r[%d]",\
					(*proc)->reg[mem[idx[0]] - 1], mem[idx[1] - 1],\
					(*proc)->reg[mem[idx[1] - 1]]);
		(*proc)->pc = ((*proc)->pc + 4) % MEM_SIZE;
	}
	else
	{
		info = get_info(NULL);
		s = (short)mem[((*proc)->pc + 3) % MEM_SIZE] << 8
			| mem[((*proc)->pc + 4) % MEM_SIZE];
		int_on_mem(mem, (*proc)->reg[mem[idx[0]] - 1],
					(*proc)->pc + (s % IDX_MOD));
		info->start = (*proc)->pc + (s % IDX_MOD);
		info->end = info->start + 4;
		if (info && info->opt[0])
			refresh_arena(info, mem, (*proc)->color);
		(*proc)->pc = ((*proc)->pc + 5) % MEM_SIZE;
	}
	free(param);
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