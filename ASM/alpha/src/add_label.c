/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 22:31:58 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/24 17:29:14 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_label(t_order *slot, char *s)
{
	char	**buf;
	_Bool	resize;
	ssize_t	i;

	if (!(slot && s))
		return ;
	resize = slot->label ? 1 : 0;
	if (!slot->label)
		slot->label = (char **)ft_memalloc(sizeof(char *) * 2);
	buf = slot->label;
	i = -1;
	while (buf[++i])
		;
	if (resize)
	{
		/*
		**	Need ft_realloc libft_judi
		**
		**	slot->label = (char **)ft_realloc((void **)&(slot->label),\
		**		(i + 1) * sizeof(char *), (i + 2) * sizeof(char *));
		*/

		slot->label = (char **)realloc((void **)&(slot->label), (i + 2) * sizeof(char *));
		buf = slot->label;
	}
	buf[i] = ft_strdup(s);
}
