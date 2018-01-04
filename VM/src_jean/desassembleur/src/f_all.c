/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_all.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 13:47:08 by jgonthie          #+#    #+#             */
/*   Updated: 2018/01/03 18:18:11 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crack.h"

static _Bool	conv_for_bitwise(int (*size)[3], int info[2])
{
	int		index;

	index = -1;
	if (info[0] == 9 || info[0] == 10 || info[0] == 13 || info[0] == 14)
	{
		while (++index < 3)
		{
			if ((*size)[index] == DIR_CODE)
				(*size)[index] = IND_CODE;
		}
		return (1);
	}
	return (0);
}

_Bool			f_all(unsigned char *instr, int info[2], int *index, int fd)
{
	int		size[3];
	char	*opc;
	int		i;
	_Bool	print;

	i = -1;
	opc = ft_strbase(instr[++(*index)], "01");
	ft_bzero(size, 3);
	if (!check_opc(&size, opc, info[0], info[1]))
		return (0);
	print = conv_for_bitwise(&size, info);
	while (++i < info[1])
	{
		if (size[i] == REG_CODE)
			write_reg(instr, index, fd);
		else if (size[i] == DIR_CODE)
			write_dir(instr, index, fd);
		else if (size[i] == IND_CODE)
			write_ind(instr, index, fd, print);
		if (i + 1 < info[1])
			write(fd, ",", 1);
	}
	return (1);
}
