/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_and.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:38:59 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/02 11:50:05 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	f_or(t_proc **proc, unsigned char *mem)
{
	int				*param;
	unsigned int	i;
	unsigned int	idx[3];
	int				j;
	int				s[2];

	j = 0;
	param = checkocp(&mem[((*proc)->pc + 1) % MEM_SIZE], 7);
	i = param_size(((*proc)->pc + 2) % MEM_SIZE, param, 0, &idx);
	if (!parse_params(param, &idx, 7, mem))
		return (execute_error(*proc, param, i + 2));
	while (j < 2)
	{
		if (param[j] == T_REG)
			s[j] = (*proc)->reg[mem[idx[j]] - 1];
		else if (param[j] == T_DIR)
			s[j] = convert(mem, idx[j], (*proc), 1);
		else if (param[j] == T_IND)
			s[j] = convert(mem, idx[j], (*proc), 0);
		j++;
	}
	(*proc)->reg[mem[idx[2]] - 1] = s[0] | s[1];
	carry(proc, (*proc)->reg[mem[idx[2]] - 1]);
	(*proc)->pc = ((*proc)->pc + i + 2) % MEM_SIZE;
	free(param);
}

/*
int		main(void)
{
	unsigned char mem[] = {6, 228, 0, 2, 255, 120, 120, 120, 1};
	t_proc *p = ft_memalloc(sizeof(t_proc));
	p->pc = 0;
	p->reg[0] = 2;
	p->reg[1] = 5000000;
	f_or(&p, mem);
	ft_printf("pc = %hu\nreg = %u\n", p->pc, p->reg[0]);
	return (0);
}*/
