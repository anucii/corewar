/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkocp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:09:44 by jpallard          #+#    #+#             */
/*   Updated: 2018/02/08 14:15:40 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	function purpose = recup type of param of the instruction remember
**	to free the array param later, *mem should be pointing on the ocp !
*/

static unsigned char	bitwise(unsigned char *o1, int i, unsigned char mem)
{
	if (i == 0)
	{
		*o1 = mem << 2;
		*o1 = *o1 >> 6;
	}
	else
	{
		*o1 = mem << 4;
		*o1 = *o1 >> 6;
	}
	return (*o1);
}

int						*checkocp(unsigned char *mem, unsigned int op_code)
{
	int				*param;
	unsigned char	o[3];
	int				i;

	i = 0;
	param = ft_memalloc(sizeof(int) * 3);
	o[0] = *mem >> 6;
	o[1] = op_code != 16 ? bitwise(&o[1], 0, *mem) : 0;
	if (op_code != 2 && op_code != 3 && op_code != 13 && op_code != 16)
		o[2] = bitwise(&o[2], 1, *mem);
	else
		o[2] = 0;
	while (i < 3)
	{
		if (o[i] == 2)
			param[i] = T_DIR;
		else if (o[i] == 1)
			param[i] = T_REG;
		else if (o[i] == 3)
			param[i] = T_IND;
		else if (o[i] == 0)
			param[i] = 0;
		i++;
	}
	return (param);
}
