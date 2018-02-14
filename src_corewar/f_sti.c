/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sti.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:41:35 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/14 17:16:08 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** stock the content of the reg passed on first param at the adress given
**by the second and third parameter % IDX_MOD
*/

int		regp(t_proc **proc, unsigned char *mem, short s, unsigned int idx[3])
{
	int				i;

	i = (*proc)->reg[mem[idx[s]] - 1];
	return (i);
}

void	info_sti(t_proc **proc, unsigned char *mem, int tar)
{
	t_info			*info;

	info = get_info(NULL);
	if (info->opt[3] && info->opt[4] && !info->opt[0])
		ft_printf("\n\t\t\tstore %d (%#4x) @ %04u",\
				convert(mem, tar, 0, 1), convert(mem, tar, 0, 1), tar);
	info->start = tar;
	info->end = (info->start + 4) % MEM_SIZE;
	if (info->opt[0])
		refresh_arena(info, mem, (*proc)->color);
}

int		endofhell(t_proc **p, unsigned char *m, int *par, unsigned int idx[3])
{
	int		t1;
	short	t;

	t1 = 0;
	t = 0;
	if (par[2] == T_REG)
		t1 = (*p)->reg[m[idx[2]] - 1];
	else
		t = m[idx[2]] << 8 | m[(idx[2] + 1)];
	return (t + t1);
}

int		paramshell(t_proc **p, unsigned char *m, int *par, unsigned int idx[3])
{
	int				i[2];
	short			s;
	unsigned short	us;

	us = 0;
	s = 0;
	i[0] = (par[1] == T_REG) ? regp(p, m, 1, idx) : 0;
	s = (m[idx[1]] << 8) | (m[(idx[1] + 1)]);
	if (par[1] == T_IND)
	{
		i[1] = chars_to_int(m, ((*p)->pc + s), 1);
		if (i[1] > 0)
			s = m[((*p)->pc + s + 2) % MEM_SIZE] << 8 |
				(m[((*p)->pc + s + 3) % MEM_SIZE]);
		else
		{
			us = m[((*p)->pc + s + 2) % MEM_SIZE] << 8 |
			(m[((*p)->pc + s + 3) % MEM_SIZE]) % IDX_MOD;
			s = 0;
		}
	}
	return (endofhell(p, m, par, idx) + s + us + i[0]);
}

void	f_sti(t_proc **proc, unsigned char *mem)
{
	int				i;
	int				tar;
	int				*param;
	unsigned int	idx[3];

	param = checkocp(&mem[((*proc)->pc + 1) % MEM_SIZE], 11);
	i = param_size(((*proc)->pc + 2) % MEM_SIZE, param, 1, &idx);
	if (!parse_params(param, &idx, 11, mem))
		return (execute_error(*proc, param, i + 2));
	tar = paramshell(proc, mem, param, idx);
	if ((tar = (*proc)->pc + ((tar) % IDX_MOD)) < 0)
		tar = MEM_SIZE + tar;
	int_on_mem(mem, (*proc)->reg[mem[((*proc)->pc + 2) % MEM_SIZE] - 1], tar);
	free(param);
	info_sti(proc, mem, tar);
	(*proc)->pc = ((*proc)->pc + 2 + i) % MEM_SIZE;
}
