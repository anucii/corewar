/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_add.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 14:47:39 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/22 18:33:34 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crack.h"

void		f_add(unsigned char *instr, int *index, int fd)
{
	char	*conv;
	int		loop;

	loop = 3;
	while (loop-- > 0)
	{
		conv = ft_strbase(instr[++(*index)], "0123456789");
		if (ft_atoi(conv) > REG_NUMBER || ft_atoi(conv) < 0)
			error("Error : St take only {REG && REG | IND}\n");
		write(fd, "r", 1);
		write(fd, conv, ft_strlen(conv));
		if (loop > 0)
			write(fd, ",", 1);
		ft_strdel(&conv);
	}
	write(fd, "\n", 1);
}
