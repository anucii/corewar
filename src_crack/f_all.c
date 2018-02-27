/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_all.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 13:47:08 by jgonthie          #+#    #+#             */
/*   Updated: 2018/02/27 14:16:19 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crack.h"

static void		f_sti_lldi_ldi_st(int (*size)[3], _Bool (*print)[3])
{
	int		index;

	index = -1;
	while (++index < 3)
	{
		if ((*size)[index] == DIR_CODE)
		{
			(*size)[index] = IND_CODE;
			(*print)[index] = 1;
		}
		else
			(*print)[index] = 0;
	}
}

static void		conv_for_bitwise(int (*size)[3], _Bool (*print)[3], \
					int info[2], int *index_instr)
{
	if (info[0] + 1 == 9 || info[0] + 1 == 12 || info[0] + 1 == 15)
	{
		(*size)[0] = IND_CODE;
		(*print)[0] = 1;
		(*index_instr) -= 1;
		return ;
	}
	if (info[0] + 1 == 11 || info[0] + 1 == 14
			|| info[0] + 1 == 10 || info[0] + 1 == 3)
	{
		f_sti_lldi_ldi_st(size, print);
		return ;
	}
}

_Bool			f_all(unsigned char *instr, int info[2], int *index, int fd)
{
	static int	size[3] = {0, 0, 0};
	_Bool		print[3];
	char		*opc;
	int			i;

	i = -1;
	opc = ft_strbase(instr[++(*index)], "01");
	while (ft_strlen(opc) != 8)
		opc = new_join(opc, "0");
	if (!check_opc(&size, opc, info[0], info[1]))
		return (0);
	conv_for_bitwise(&size, &print, info, index);
	while (++i < info[1])
	{
		if (size[i] == REG_CODE)
			write_reg(instr, index, fd);
		else if (size[i] == DIR_CODE)
			write_dir(instr, index, fd);
		else if (size[i] == IND_CODE)
			write_ind(instr, index, fd, print[i]);
		if (i + 1 < info[1])
			write(fd, ",", 1);
	}
	return (1);
}
