/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 15:50:56 by jdaufin           #+#    #+#             */
/*   Updated: 2018/01/06 17:46:48 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	NB : the subject sets the padding to 32 bytes by line but the supplied VM
**	displays twice this amount by line
*/

_Bool	dump_mem(unsigned char *mem)
{
	ssize_t	i;
	ssize_t	pad;
	_Bool	ret;
	t_info	*info;

	info = get_info(NULL);
	if (!mem || info->opt[0] ||!(info->opt[1] && (ret = (global_timer(CHECK)\
						== info->opt[2]))))
		return (0);
	i = -1;
	pad = 32;
	while (++i < MEM_SIZE)
	{
		if (!(i % pad))
			ft_printf(i ? "%#06x: " : "%#05x: ", i);
		ft_printf("%02hhx%c", mem[i], (i + 1) % pad ? ' ' : '\n');
	}
	if (MEM_SIZE & 1)
		ft_printf("\n");
	return (ret);
}
