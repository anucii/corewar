/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 20:29:32 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/14 21:24:21 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "judi.h"

/*
**	param_size() returns the size of the set of parameters types passed by the
**	int pointer; if dir_as_addr is TRUE, then DIR_SIZE (4 by default) is reset 
**	to IND_SIZE (2 by default)
*/

unsigned int	param_size(int *param, _Bool dir_as_addr)
{
	ssize_t			i;
	unsigned int	ret;

	if (!param)
		error_vm("param_size() called with a null pointer as parameter");
	i = -1;
	ret = 0;
	while (++i < 3)
	{
		if (param[i] == T_REG)
			ret += REG_REF_SIZE;
		else if (param[i] == T_IND)
			ret += IND_SIZE;
		else if (param[i] == T_DIR)
			ret += dir_as_addr ? IND_SIZE : DIR_SIZE;
	}
	return (ret);
}

/*
 * MAINTEST
 * dependencies :
 * - checkocp.c
 * - libft.a (ft_memalloc in checkocp())
 * - error_vm.c

int	main(void)
{
	unsigned char	mem1[] = \
	{0x06, 0x64, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01}; // {and r1,%0,r1} as in subject p.12
	unsigned char	mem2[] = \
	{0x0a, 0xa4, 0x00, 0x05, 0x00, 0x03, 0x01}; // {ldi %5,%3,r1},\
												OCP : Ob{DIR_CODE,DIR_CODE,REG_CODE,0b00} == 0xa4
	int				*param[2];

	param[0] = checkocp(&mem1[1]);
	param[1] = checkocp(&mem2[1]);
	ft_printf("param_size(reg, dir, reg) w/ 'and' = %u (expected : 6)\n,", param_size(param[0], 0));
	ft_printf("param_size(dir, dir, reg) w/ 'ldi' = %u (expected : 5)\n", param_size(param[1], 1));
	return (0);
}
 */
