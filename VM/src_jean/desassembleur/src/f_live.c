/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_live.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:56:13 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/28 11:23:34 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crack.h"

void		f_live(unsigned char *instr, int *index, int fd)
{
	//int		size[3];
	char	*tmp_2;
	char	*tmp_1;
	char	*conv;
	char	*join;

	tmp_2 = to_hexa(instr[++(*index)], instr[++(*index)]);
	tmp_1 = to_hexa(instr[++(*index)], instr[++(*index)]);
	join = ft_strjoin(tmp_2, tmp_1);
	conv = ft_to_deci(join, "0123456789abcdef");
	if (ft_strlen(join) == 8)
	write(fd, "%", 1);
	write(fd, conv, ft_strlen(conv));
	write(fd, "\n", 1);
	ft_strdel(&tmp_2);
	ft_strdel(&tmp_1);
	ft_strdel(&conv);
	ft_strdel(&join);
}
