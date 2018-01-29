/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_hdr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:17:57 by jdaufin           #+#    #+#             */
/*   Updated: 2018/01/25 18:31:30 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_proc	**proc_hdr(t_req req)
{
	static t_proc	**hdr = NULL;
	static _Bool	b_init = 0;

	if (!b_init && (req == HDR_INIT))
	{
		hdr = ft_memalloc(sizeof(t_proc *));
		b_init = 1;
	}
	return (hdr);
}
