/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_and.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:38:59 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/18 16:05:18 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "judi.h"

void	f_xor(t_proc **proc, unsigned char *mem)
{
	int				*param;
	unsigned int	i;
	unsigned int	idx[3];
	int				j;
	unsigned int	s[2];

	j = 0;
	param = checkocp(&mem[((*proc)->pc + 1) % MEM_SIZE]);
	i = param_size(((*proc)->pc + 2) % MEM_SIZE, param, 0, &idx);
	//if (!parse_params(param, &idx, 6, mem)
	//	execute_error();
	while (j < 2)
	{
		if (param[j] == T_REG)
			s[j] = (*proc)->reg[mem[idx[0]] - 1];
		else
			s[j] = convert( mem, idx, param, j);
		j++;
	}
	(*proc)->reg[mem[idx[2]] - 1] = s[0] ^ s[1];
	(*proc)->pc = ((*proc)->pc + i + 2) % MEM_SIZE;
	return ;
}

/*for test purpose
int		main(void)
{
	unsigned char mem[] = {6, 164, 0, 255, 255, 255, 0, 0, 0, 16, 1};
	t_proc *p = ft_memalloc(sizeof(t_proc));
	p->pc = 0;
	p->reg[0] = 2;
	p->reg[1] = 5000000;
	f_xor(&p, mem);
	ft_printf("pc = %hu\nreg = %u\n", p->pc, p->reg[0]);
	return (0);
}*/
