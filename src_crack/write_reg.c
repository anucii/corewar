/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_reg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 11:50:21 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/28 12:38:56 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crack.h"

void		write_reg(unsigned char *instr, int *index, int fd)
{
	char	*deci;
	char	*o;

	write(fd, "r", 1);
	o = ft_strbase(instr[++(*index)], "0123456789abcdef");
	deci = ft_to_deci(o, "0123456789abcdef");
	write(fd, deci, ft_strlen(deci));
	ft_strdel(&o);
	ft_strdel(&deci);
}
