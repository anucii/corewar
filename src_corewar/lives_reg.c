/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lives_reg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 18:50:21 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/08 14:02:09 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	player_lives() stores both the number of lives of a player (in counts[i][0]
**	returned on any type of request) and the last live recorded (in counts[i][1]
**	accessed with a CHECK request), it also handles the displaying
**	of the life declaration of the verbose mode
*/

int		player_lives(t_req req, int *(*val)[2], t_info *info, t_proc *proc)
{
	static int	counts[MAX_PLAYERS][2];
	int			i;

	i = -1;
	if (req == REINIT)
		while (++i < MAX_PLAYERS)
			counts[i][0] = 0;
	else
		while (++i < info->nb_player)
			if (*((*val)[1]) == info->id_player[i])
			{
				if (req == LIVE)
				{
					++(counts[i][0]);
					*((*val)[0]) = *((*val)[1]);
					counts[i][1] = global_timer(CHECK);
					if (!info->opt[0] && info->opt[3] && info->opt[4])
						ft_printf("\n[LIVE(cy:%04u)] : le processus %04u \
(player %d)dit que le joueur %d(%s) est en vie\n", counts[i][1], proc->pid, \
proc->champ.id, info->id_player[i], info->name[i]);
				}
				return (counts[i][req == CHECK ? 1 : 0]);
			}
	return (0);
}

void	lives_reg(t_req request, int num, t_info *info, t_proc *proc)
{
	static int	last_id = 0;
	int			*val[2];
	int			i;

	if (!info)
		return ;
	val[0] = &last_id;
	if (request == LIVE)
	{
		val[1] = &num;
		player_lives(LIVE, &val, info, proc);
		return ;
	}
	if (request == CHECK)
	{
		i = -1;
		while (++i < info->nb_player)
			if (last_id == info->id_player[i])
			{
				ft_printf("[WIN(cy:%04u)]: le joueur %d(%s) a gagne\n",\
						global_timer(CHECK), info->id_player[i], info->name[i]);
				return ;
			}
		ft_printf("Stalemate : no player has ever been declared alive.\n");
	}
}
