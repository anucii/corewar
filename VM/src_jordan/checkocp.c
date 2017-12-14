/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkocp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:09:44 by jpallard          #+#    #+#             */
/*   Updated: 2017/12/14 11:29:27 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/jordan.h"

/*
**function purpose = recup type of param of the instruction remember
**to free the array param later, *mem should be pointing on the ocp !
*/

static unsigned char		bitwise(unsigned char o, int i)
{
	if (i == 0)
	{
		o = o << 2;
		o = o >> 6;
	}
	else
	{
		o = o << 4;
		o = o >> 6;
	}
	return (o);
}

int		*checkocp(unsigned char *mem)
{
	int		*param;
	unsigned char	o[3];
	int			i;

	i = 0;
	param = ft_memalloc(sizeof(int) * 3);
	o[0] = *mem >> 6;
	o[1] = bitwise(*mem, 0);
	o[2] = bitwise(*mem, 1);
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

/* if you need a quick test
int main(void)
{
	unsigned char test = 0xf8;
	int		*tab = NULL;
	int i = 0;
	tab = checkocp(test);
	while (i < 3)
	{
		ft_printf("%d\n", tab[i]);
		i++;
	}
	return (0);
}*/
