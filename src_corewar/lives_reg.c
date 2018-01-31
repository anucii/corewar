/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lives_reg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 18:50:21 by jdaufin           #+#    #+#             */
/*   Updated: 2018/01/31 15:23:24 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	lives_reg(t_req request, int num, t_info *info, t_proc *proc)
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
				if (info->opt[0] || (info->opt[3] && !info->opt[4]))
					return ;
				ft_printf("\n[LIVE(cy:%04u)] : le processus %04u (player %d) dit\
 que le joueur %d(%s) est en vie\n", global_timer(CHECK), proc->pid,\
proc->champ.id, info->id_player[i], info->name[i]);
				return ;
			}
	}
	if (request == CHECK)
	{
		i = -1;
		while (++i < info->nb_player)
			if (last_id == info->id_player[i])
			{
				ft_printf("[WIN(cy:%04u)]: le joueur %d(%s) a gagne\n",\
						global_timer(CHECK), info->id_player[i],\
						info->name[i]);
				return ;
			}
		ft_printf("Stalemate : no player has ever been declared alive.\n");
	}
}
