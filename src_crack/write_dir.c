/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 11:50:40 by jgonthie          #+#    #+#             */
/*   Updated: 2018/01/04 15:18:33 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crack.h"

void		write_dir(unsigned char *instr, int *index, int fd)
{
	char	*deci;
	char	*hexa;
	char	*o1;
	char	*o2;

	o1 = to_hexa(instr[(*index) + 1], instr[(*index) + 2]);
	o2 = to_hexa(instr[(*index) + 3], instr[(*index) + 4]);
	(*index) += 4;
	hexa = ft_strjoin(o1, o2);
	write(fd, "%", 1);
	deci = ft_to_deci(hexa, "0123456789abcdef");
	write(fd, deci, ft_strlen(deci));
	ft_strdel(&deci);
	ft_strdel(&hexa);
	ft_strdel(&o2);
	ft_strdel(&o1);
}
