/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sti.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:41:35 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/05 18:06:12 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** stock the content of the reg passed on first param at the adress given
**by the second and third parameter % IDX_MOD
*/

void	f_sti(t_proc **proc, unsigned char *mem)
{
	short			s;
	unsigned short	s1 = 0;
	short			t;
	int				t1 = 0;
	int				i;
	int				target;
	int				*param;
	unsigned int	idx[3];
	t_info			*info;


	param = checkocp(&mem[((*proc)->pc + 1) % MEM_SIZE], 11);
	i = param_size(((*proc)->pc + 2) % MEM_SIZE, param, 1, &idx);
	if (!parse_params(param, &idx, 11, mem))
		return (execute_error(*proc, param, i + 2));
	info = get_info(NULL);
	if (param[1] == T_REG)
	{
		if (((*proc)->reg[mem[idx[1]] - 1]) > INT_MAX)
			s = (short)(*proc)->reg[mem[idx[1]] - 1];
		else
		{
			s1 = (unsigned short)(*proc)->reg[mem[idx[1]] - 1];
			s = 0;
		}/*
		s1 = (*proc)->reg[mem[idx[1]] - 1];
		s = 0;*/
	}
	else
	{
		s = ((short)mem[idx[1]] << 8) |
			(mem[(idx[1] + 1)]);
		if (param[1] == T_IND)
		{
			target = chars_to_int(mem, ((*proc)->pc + s), 1);
			if (target > 0)
			{
				s = (short)mem[((*proc)->pc + s + 2) % MEM_SIZE] << 8 |
				(mem[((*proc)->pc + s + 3) % MEM_SIZE]);
			}
			else
			{
				s1 = (unsigned short)mem[((*proc)->pc + s + 2) % MEM_SIZE] << 8 |
				(mem[((*proc)->pc + s + 3) % MEM_SIZE]) % IDX_MOD;
				s = 0;
			}
				//s = (short)mem[((*proc)->pc + s + 2) % MEM_SIZE] << 8 |
				//(mem[((*proc)->pc + s + 3) % MEM_SIZE]) % IDX_MOD;
		}
	}
	if (param[2] == T_REG)
	{/*
		if (((*proc)->reg[mem[idx[2]] - 1]) > USHRT_MAX)
			t = (short)(*proc)->reg[mem[idx[2]] - 1];
		else
		{
			t1 = (unsigned short)(*proc)->reg[mem[idx[2]] - 1];
			t = 0;
		}*/
		t1 = (*proc)->reg[mem[idx[2]] - 1];
		t = 0;
	}
	else
		t = (short)mem[idx[2]] << 8 |
			mem[(idx[2] + 1)];
	if ((target = (*proc)->pc + ((s + t1 + t + s1) % IDX_MOD)) < 0)
		target = MEM_SIZE + target;
// 	ft_printf("target = %d\n", target);
	int_on_mem(mem,
			(*proc)->reg[mem[((*proc)->pc + 2) % MEM_SIZE] - 1],
			target);
	if (info->opt[3] && info->opt[4] && !info->opt[0])
		ft_printf("\n\t\t\tstore %d (%#4x) @ %04u  s = %hd , t = %hd", convert(mem, target, 0, 1),\
				convert(mem, target, 0, 1), target, s, t);
	info->start = (*proc)->pc + ((s + t) % IDX_MOD);
	info->end = info->start + 4;
	if (info->opt[0])
		refresh_arena(info, mem, (*proc)->color);
	(*proc)->pc = ((*proc)->pc + 2 + i) % MEM_SIZE;
}
/*
int		main(void)
{
	unsigned char pq[] = {0 ,0 , 0, 0, 11, 100, 12, 0, 0, 12, 1, 0, 0, 11, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	t_proc *p;
	unsigned char mem[4096] = {0} ;


	p = ft_memalloc(sizeof(t_proc));
	p->pc = 4;
	p->reg[11] = -6;
	p->reg[0] = 1;
	p->reg[1] = 7;
	ft_memcpy(mem, pq, 36);
	f_sti(&p, mem);
	int i = 0;
	while (i < 4096)
	{
		ft_printf("%hhu\n", mem[i]);
		i++;
	}
	unsigned short d = 46;
	unsigned short s = -186;
	s = d + s;
	ft_printf("test = %hu\n", s);
	return (0);
}*/
