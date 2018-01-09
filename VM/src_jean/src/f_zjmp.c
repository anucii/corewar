/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_zjmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:40:44 by jdaufin           #+#    #+#             */
/*   Updated: 2018/01/09 18:12:35 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**2 unsigned char transferred over 1 short to have the real number in case you 
**wondering on the next formula, otherwise function who jump to adress 
**passed % IDX_MOD
*/

void	f_zjmp(t_proc **proc, unsigned char *mem)
{
	short i;

	(void)mem;
	i = ((short)(*proc)->o_mem[1] << 8)
		| (*proc)->o_mem[2];
	if ((*proc)->carry == 1)
		(*proc)->pc = (((*proc)->pc + (i % IDX_MOD)) % MEM_SIZE);
	else
		(*proc)->pc = (((*proc)->pc + 3) % MEM_SIZE);
	return ;
}

/* for quick test
int main(void)
{
	unsigned char i[4] = {'9' , 255 , 255, '0'};
	t_proc	*p;

	p = ft_memalloc(sizeof(t_proc));
	p->carry = 1;
	p->pc = 0;
	f_zjmp(&p, i);
	ft_printf("%u\n", p->pc);
	return(0);
}*/
