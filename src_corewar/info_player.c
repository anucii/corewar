/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:13:32 by jdaufin           #+#    #+#             */
/*   Updated: 2018/01/04 16:58:53 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	check_ids(t_info *info)
{
	int	i[2];

	i[0] = -1;
	while (++i[0] < info->nb_player)
	{
		i[1] = -1;
		while (++i[1] < i[0])
			if (info->id_player[i[0]] == info->id_player[i[1]])
				error_vm(""RED"Error : player id duplicated"RESET"");
	}
}

void		init_ll(t_info *info)
{
	ssize_t	i;

	i = -1;
	while (++i < MAX_PLAYERS)
		info->ll_player[i] = 0;
}

void		info_player(t_info *info, int nb_player)
{
	info->nb_player = nb_player;
	init_ll(info);
	check_ids(info);
}
