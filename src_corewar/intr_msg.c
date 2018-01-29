/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intr_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 18:22:39 by jdaufin           #+#    #+#             */
/*   Updated: 2018/01/25 15:17:34 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Message to introduce contestants at the beginning of the party.
*/

static void	announce(t_proc *p)
{
	if (!p)
		return ;
	announce(p->next);
	ft_printf("* Player %d, %s !\n", p->champ.id, p->champ.name);
}

void		intr_msg(t_proc **p)
{
	t_info	*info;

	if (!p)
		return ;
	ft_printf("Introducing contestants...\n");
	info = get_info(NULL);
	if (!info)
		error_vm("DBG : info is set to NULL");
	announce(*p);
}
