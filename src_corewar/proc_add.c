/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 20:06:18 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/08 14:02:33 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	proc_append() appends a processus to the tail of the list whereas
**	proc_add() prepends it at its head, which implies, concerning the last
**	case, that the added link is a new one, with a NULL 'next' field (those
**	pointers beeing lost otherwise)
*/

void	proc_append(t_proc **proc_hdr, t_proc *link)
{
	t_proc	*buf;

	if (!(proc_hdr && link))
		return ;
	buf = *proc_hdr;
	while (buf->next)
		buf = buf->next;
	buf->next = link;
}

void	proc_add(t_proc **proc_hdr, t_proc *link)
{
	if (!(proc_hdr && link))
		return ;
	link->next = *proc_hdr;
	*proc_hdr = link;
}
