/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sti.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:41:35 by jdaufin           #+#    #+#             */
/*   Updated: 2018/01/03 19:35:08 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** stock the content of the reg passed on first param at the adress given
**by the second and third parameter % IDX_MOD
*/

void	f_sti(t_proc **proc, unsigned char *mem)
{
	unsigned short		s;
	unsigned short		t;
	unsigned int		i;
	int					*param;
	unsigned int		idx[3];
	t_info				*info;


	param = checkocp(&mem[((*proc)->pc + 1) % MEM_SIZE]);
	i = param_size(((*proc)->pc + 2) % MEM_SIZE, param, 1, &idx);
	info = get_info(NULL);
	if (param[1] == T_REG)
		s = (unsigned short)(*proc)->reg[mem[idx[1]] - 1];
	else
	{
		s = ((short)mem[idx[1]] << 8) |
			(mem[(idx[1] + 1)]);
		if (param[1] == T_IND)
			s = (short)mem[(*proc)->pc + s + 2] << 8 |
				(mem[(*proc)->pc + s + 3]) % IDX_MOD;
	}
	if (param[2] == T_REG)
		t = (unsigned short)(*proc)->reg[mem[idx[2]] - 1];
	else
		t = (short)mem[idx[2]] << 8 |
			mem[(idx[2] + 1)];
	int_on_mem(mem,
			(*proc)->reg[mem[((*proc)->pc + 2) % MEM_SIZE] - 1],
			(*proc)->pc + ((s + t) % IDX_MOD));
	info->start = (*proc)->pc + ((s + t) % IDX_MOD);
	info->end = info->start + 4;
	if (info->opt[0])
		refresh_arena(info, mem, (*proc)->color);
	(*proc)->pc += 2 + i;
	return ;
}

/*
int		main(void)
{
	unsigned char mem[] = {11, 120, 12, 0, 7, 0, 0, 1, 0, 0, 11, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0};
	t_proc *p;

	p = ft_memalloc(sizeof(t_proc));
	p->pc = 0;
	p->reg[11] = 5413584;
	p->reg[0] = 1;
	p->reg[1] = 7;
	f_sti(&p, mem);
	int i = 0;
	while (i < 32)
	{
		ft_printf("%hhu\n", mem[i]);
		i++;
	}
	return (0);
}*/
