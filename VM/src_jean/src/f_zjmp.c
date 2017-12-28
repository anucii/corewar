/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_zjmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:40:44 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/28 17:12:53 by jdaufin          ###   ########.fr       */
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
	unsigned short i;

	i = ((short)mem[((*proc)->pc + 1) % MEM_SIZE] << 8) 
		| mem[((*proc)->pc + 2) % MEM_SIZE];
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
