/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_live.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:35:02 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/08 12:27:14 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	f_live :
**	See maintest for further explanation.
**	dependencies : chronos.c, timer.c, chars_to_int.c, libft.a, [libftprintf.a]
*/

void	f_live(t_proc **proc, unsigned char *mem)
{
	unsigned int	val;
	t_info			*info;

	if (!mem)
		error_vm("Error : null memory address.");
	if (!(proc && *proc))
		error_vm("Error : null process sent to f_live");
	val = chars_to_int(mem, (*proc)->pc + 1, 1);
	chronos(*proc, LIVE, val);
	info = get_info(NULL);
	if (info->opt[3] && info->opt[4] && !info->opt[0])
		ft_printf("\n\t\t\tlive %d(%#4x)", val, val);
	(*proc)->pc = ((*proc)->pc + 5) % MEM_SIZE;
}
