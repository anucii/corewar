/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_aff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 17:09:47 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/22 18:24:04 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crack.h"

void		f_aff(unsigned char *instr, int *index, int fd)
{
	instr = NULL;
	*index = 0;
	fd = 0;
	char	*conv;

	conv = ft_strbase(instr[++(*index)], "0123456789");
	if (ft_atoi(conv) > REG_NUMBER || ft_atoi(conv) < 0)
		error("Error : aff take only {REG}");
	write(fd, "r", 1);
	write(fd, conv, ft_strlen(conv));
	write(fd, "\n", 1);
	ft_strdel(&conv);
}
