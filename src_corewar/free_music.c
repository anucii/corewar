/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_music.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:58:18 by jpallard          #+#    #+#             */
/*   Updated: 2018/02/06 17:06:32 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	free_music(t_info *info)
{
	int		i;

	i = 0;
	while (info->bgm[i])
	{
		FMOD_Sound_Release(info->bgm[i]);
		i++;
	}
	FMOD_System_Close(info->s);
	FMOD_System_Release(info->s);
}
