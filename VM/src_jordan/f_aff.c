/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_aff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:44:25 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/14 16:33:39 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/jordan.h"

/*
**print a character stocked in the reg passed in parameter apply %256 on it
*/

void	f_aff(t_proc **proc, unsigned char *mem)
{/* need to create execute_error
	if(mem[(*proc)->pc + 1] != 1)
		execute_error();
	else if(mem[(*proc)->pc + 2] > REG_NUMBER)
		execute_error();
	else*/
		ft_printf("%c\n", (*proc)->reg[mem[(*proc)->pc + 2]] % 256);
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
}