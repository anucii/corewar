/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:13:34 by jpallard          #+#    #+#             */
/*   Updated: 2017/12/13 20:31:52 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/jordan.h"

void	execute_order(unsigned char *mem, t_proc *p)
{
	int		i;

	i = 0;
	mem = mem + p->pc;
	while (i < 17)
	{
		if (*mem ==  g_op_tab[i][3])
		{
			g_op_tab[i].func(&p, mem);
			return ;
		}
		i++;
	}
	p->pc++;
}

/*
**	The run function manages the cycles, it stops only when there is no
**	more processus alive.
*/

void	run(unsigned char *mem, t_proc **p)
{
	_Bool			c;
	unsigned int	i;

	if (!(mem && p))
		return ;
	i = 0;
	c = 1;
	while (c)
	{
		while (timer(CHECK) < deadline(CHECK))
		{
			timer(INCR);
		}
		c = 0;
		while ()
		{}
		deadline(DECR);
	}
	/*
	int		i;

	while(CYCLE_TO_DIE > 0 && p)
	{
		if (
		i = nbj;
		while(i > 0)
		{
			execute_order(mem, p[nbj]);
			i--;
		}
		timer(INCR);
	}
	*/
}
