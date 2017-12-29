/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lives_reg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 18:50:21 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/29 19:23:12 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	lives_reg(t_req request, int num, t_info *info)
{
	static int	last_id = 0;
	int			i;

	if (!info)
		return ;
	if (request == LIVE)
	{
		i = -1;
		while (++i < info->nb_player)
			if (num == info->id_player[i])
			{
				last_id = num;
				ft_printf("un processus dit que le joueur %d(%s) est en \
vie\n", info->id_player[i], info->name[i]);
				return ;
			}
	}
	if ((request == CHECK) && last_id)
	{
		i = -1;
		while (++i < info->nb_player)
			if (last_id == info->id_player[i])
				ft_printf("le joueur %d(%s) a gagne\n", info->id_player[i],\
						info->name[i]);
	}
}
