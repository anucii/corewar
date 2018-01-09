/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_aff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:44:25 by jdaufin           #+#    #+#             */
/*   Updated: 2018/01/09 18:13:23 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**print a character stocked in the reg passed in parameter apply %256 on it
*/

void	f_aff(t_proc **proc, unsigned char *mem)
{/* need to create execute_error
	if(mem[((*proc)->pc + 1) % MEM_SIZE] != 1)
		execute_error();
	else if(mem[((*proc)->pc + 2) % MEM_SIZE] > REG_NUMBER)
		execute_error();
	else*/
	t_info	*info;

	(void)mem;
	info = get_info(NULL);
	if (info && !info->opt[0])
		ft_printf("%c\n",
				(*proc)->reg[(*proc)->o_mem[2] - 1] % 256);
	(*proc)->pc = ((*proc)->pc + 3) % MEM_SIZE;
	return ;
}

/*quick test
int		main(void)
{
	t_proc *p;
	unsigned char mem[4] = {16, 1, 5, 89};

	p = ft_memalloc(sizeof(t_proc));
	p->pc = 0;
	p->reg[5] = 80;
	f_aff(&p, mem);
	return(0);
}*/
