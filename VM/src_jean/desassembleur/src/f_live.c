/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_live.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:56:13 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/22 19:56:03 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crack.h"

void		f_live(unsigned char *instr, int *index, int fd)
{
	char	*conv;
	char	*o1;
	char	*o2;

	*index += 1;
	o1 = ft_strbase(instr[++(*index)], "0123456789");
	o2 = ft_strbase(instr[++(*index)], "0123456789");
	conv = ft_strjoin(o1, o2);
	write(fd, "%", 1);
	write(fd, conv, ft_strlen(conv));
	write(fd, "\n", 1);
	ft_strdel(&o1);
	ft_strdel(&o2);
	ft_strdel(&conv);
}
