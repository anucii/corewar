/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_ld.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 17:04:53 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/27 20:00:22 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crack.h"

void		f_ld(unsigned char *instr, int *index, int fd)
{
	int		size[3];
	char	*tmp_2;
	char	*tmp_1;
	char	*conv;
	char	*opc;
	char	*o;
	int		index;

	index = -1;
	opc = ft_strbase(instr[++(*index)], "01");
	ft_bzero(size, 3);
	check_opc(&size, opc);
	if (size[0] == T_DIR)
	{

	}
	else if (size[0] == T_REG)
	{
	tmp_2 = to_hexa(instr[++(*index)], instr[++(*index)]);
	tmp_1 = ft_to_deci(tmp_2, "0123456789abcdef");
	write(fd, tmp_1, ft_strlen(tmp_1));
	write(fd, ",r", 2);
	o = ft_strbase(instr[++(*index)], "0123456789abcdef");
	conv = ft_to_deci(o, "0123456789abcdef");
	write(fd, conv, ft_strlen(conv));
	write(fd, "\n", 1);
	ft_strdel(&tmp_2);
	ft_strdel(&tmp_1);
	ft_strdel(&conv);
	ft_strdel(&o);
	}
}
