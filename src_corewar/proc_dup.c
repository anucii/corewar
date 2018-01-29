/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 20:51:34 by jdaufin           #+#    #+#             */
/*   Updated: 2018/01/25 18:32:29 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_proc	*proc_dup(t_proc **proc_hdr, t_proc *link)
{
	t_proc	*new;

	if (!(proc_hdr && link))
		return (NULL);
	if ((new = ft_memalloc(sizeof(t_proc))))
	{
		new = ft_memcpy(new, link, sizeof(t_proc));
		proc_add(proc_hdr, new);
	}
	return (new);
}
