/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 11:51:01 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/28 18:27:20 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crack.h"

void		write_ind(unsigned char *instr, int *index, int fd, _Bool print)
{
	char	*hexa;
	char	*deci;

	hexa = to_hexa(instr[++(*index)], instr[++(*index)]);
	deci = ft_to_deci(hexa, "0123456789abcdef");
	if (print)
		write(fd, "%", 1);
	write(fd, deci, ft_strlen(deci));
	ft_strdel(&hexa);
	ft_strdel(&deci);
}
