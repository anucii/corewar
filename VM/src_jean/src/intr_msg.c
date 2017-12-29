/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intr_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 18:22:39 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/29 20:04:37 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Message to introduce contestants at the beginning of the party.
*/

void	intr_msg(t_proc **p)
{
	ssize_t	i;
	t_info	*info;

	if (!p)
		return ;
	i = -1;
	ft_printf("Introducing contestants...\n");
	info = get_info(NULL);
	if (!info)
		error_vm("DBG : info is set to NULL");
	while (++i < info->nb_player)
	{
		if (p[i])
			ft_printf("Player %d, %s!\n",\
					p[i]->champ.id, p[i]->champ.name);
	}
}
