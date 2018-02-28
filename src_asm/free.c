/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:59:46 by jgonthie          #+#    #+#             */
/*   Updated: 2018/02/27 17:21:03 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		free_doublechar(char **tab, int size)
{
	int		index;

	index = -1;
	if (size == 0)
		return ;
	while (++index < size)
		ft_strdel(&tab[index]);
	ft_memdel((void**)&tab);
}

void		free_order(t_order **tab, int size)
{
	int		index;
	int		size_param;
	int		size_label;

	index = -1;
	while (++index < size)
	{
		if (tab[index]->nb_param > 0)
		{
			size_param = -1;
			while (++size_param < tab[index]->nb_param)
				ft_strdel(&tab[index]->param[size_param]);
			ft_memdel((void**)&tab[index]->param);
		}
		if (tab[index]->nb_label > 0)
		{
			size_label = -1;
			while (++size_label < tab[index]->nb_label)
				ft_strdel(&tab[index]->label[size_label]);
			ft_memdel((void**)&tab[index]->label);
		}
		ft_memdel((void**)&tab[index]);
	}
	ft_memdel((void**)&tab);
}
