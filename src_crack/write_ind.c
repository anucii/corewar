/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 11:51:01 by jgonthie          #+#    #+#             */
/*   Updated: 2018/02/02 13:15:16 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crack.h"

void		write_ind(unsigned char *instr, int *index, int fd, _Bool print)
{
	char	*hexa;
	char	*deci;

	hexa = to_hexa(instr[(*index) + 1], instr[(*index) + 2]);
	(*index) += 2;
	deci = ft_to_deci(hexa, "0123456789abcdef");
	if (print)
		write(fd, "%", 1);
	write(fd, deci, ft_strlen(deci));
	ft_strdel(&hexa);
	ft_strdel(&deci);
}
