/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_live.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:35:02 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/14 17:43:27 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "judi.h"

/*
**	f_live : 
**	See maintest for further explanation.
**	dependencies : chronos.c, timer.c, chars_to_int.c, libft.a, [libftprintf.a]
*/

void	f_live(t_proc **proc, unsigned char *mem)
{
	unsigned int	val;

	if (!mem)
		error_vm("Null memory address.");
	if (!(proc && *proc))
		error_vm("Null process sent to f_live");
	val = chars_to_int(&mem[((*proc)->pc + 1) % MEM_SIZE]);
	chronos(*proc, LIVE, val);
	(*proc)->pc = ((*proc)->pc + 5) % MEM_SIZE;
	return ;
}
/*
int	main(void)
{
	_Bool			alive;
	unsigned char	mem[] = {1, 0xff, 0xff, 0xff, 0xfe};
	t_proc			*proc = ft_memalloc(sizeof(t_proc));

	proc->pc = 0;
	alive = chronos(proc, CHECK, proc->life.player);
	ft_printf("proc %u says player %u is %s.\n", proc->pid, proc->life.player, alive ? "alive" : "dead");
	f_live(&proc, mem);
	alive = chronos(proc, CHECK, proc->life.player);
	ft_printf("proc %u says player %u is %s.\n", proc->pid, proc->life.player, alive ? "alive" : "dead");
	return (0);
}
*/
