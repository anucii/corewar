/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 11:06:30 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/30 14:30:27 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_info		*ini_info(int (*tab)[2])
{
	t_info		*info;
	int 		index;

	index = -1;
	info = ft_memalloc(sizeof(t_info));
	while (++index)
		ft_memset(info->name[index], 0, 255);
	ft_memset(info->opt, 0, 5);
	info->id_player[0] = -1;
	info->id_player[1] = -2;
	info->id_player[2] = -3;
	info->id_player[3] = -4;
	info->nb_player = 0;
	info->win = NULL;
	info->start = 0;
	info->end = 0;
	(*tab)[0] = 0;
	(*tab)[1] = -1;
	return (info);
}
