/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 11:06:30 by jgonthie          #+#    #+#             */
/*   Updated: 2018/02/14 14:17:45 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_info		*ini_music(t_info *info)
{
	FMOD_RESULT		res[7];
	int				i;

	i = 0;
	res[0] = FMOD_System_Create(&info->s);
	res[1] = FMOD_System_Init(info->s, 5, FMOD_INIT_NORMAL, NULL);
	res[2] = FMOD_System_CreateSound(info->s, "./include/8_bit_trauma.mp3",
							FMOD_LOOP_NORMAL, 0, &info->bgm[0]);
	res[3] = FMOD_System_CreateSound(info->s, "./include/Tetris.mp3",
							FMOD_LOOP_NORMAL, 0, &info->bgm[1]);
	res[4] = FMOD_System_CreateSound(info->s, "./include/AR.mp3",
							FMOD_LOOP_NORMAL, 0, &info->bgm[2]);
	res[5] = FMOD_System_CreateSound(info->s, "./include/ready.ogg",
							FMOD_CREATESAMPLE, 0, &info->bgm[3]);
	res[6] = FMOD_System_CreateSound(info->s, "./include/fatality.mp3",
							FMOD_CREATESAMPLE, 0, &info->bgm[4]);
	while (i < 7)
	{
		if (res[i] != FMOD_OK)
			exit(EXIT_FAILURE);
		i++;
	}
	return (info);
}

t_info		*ini_info(int (*tab)[2])
{
	t_info	*info;
	int		index;

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
