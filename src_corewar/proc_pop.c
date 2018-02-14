/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 20:20:31 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/14 14:25:39 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	proc_pop(t_proc **proc_hdr, t_proc *link)
{
	t_proc	*buf[2];
	t_info	*info;

	if (!(proc_hdr && link))
		return ;
	buf[0] = *proc_hdr;
	while (buf[0] && (buf[0] != link))
	{
		buf[1] = buf[0];
		buf[0] = buf[0]->next;
	}
	if (buf[0] == link)
	{
		if (buf[0] == *proc_hdr)
			*proc_hdr = buf[0]->next;
		else
			buf[1]->next = buf[0]->next;
		free(link);
		link = NULL;
	}
	info = get_info(NULL);
	FMOD_System_PlaySound(info->s, info->bgm[4], 0, false, NULL);
}
