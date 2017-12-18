/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_and.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:38:59 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/18 15:24:37 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/jordan.h"

unsigned int	convert(unsigned char *mem, unsigned int idx[3], int *param, int j)
{
	unsigned int	o;

	o = 0;
	if (param[j] == T_DIR)
		o = ((unsigned int)mem[idx[j]] << 24) |
			((unsigned int)mem[idx[j] + 1] << 16) |
			((unsigned int)mem[idx[j] + 2] << 8) |
			(mem[idx[j] + 3]);
	else if (param[j] == T_IND)
		o = ((unsigned short)mem[idx[j]] << 8) | (mem[idx[j] + 1]);
	return(o);
}
