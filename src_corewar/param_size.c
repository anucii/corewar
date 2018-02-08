/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 20:29:32 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/08 14:00:18 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	param_size() returns the size of the set of parameters types passed by the
**	int pointer; if dir_as_addr is TRUE, then DIR_SIZE (4 by default) is reset
**	to IND_SIZE (2 by default)
**	NEW FUNCTIONALITY : sets the index of each parameter on the memory space
**	provided that the p_first parameter is correctly modulo'd by MEM_SIZE in
**	the calling function.
*/

unsigned int	param_size(unsigned int p_first, int *param, _Bool dir_as_addr,\
		unsigned int (*p_idx)[3])
{
	ssize_t			i;
	unsigned int	ret;

	if (!param)
		error_vm("param_size() called with a null pointer as parameter");
	i = -1;
	ret = 0;
	while (++i < 3)
	{
		if (p_idx)
			(*p_idx)[i] = (p_first + ret) % MEM_SIZE;
		if (param[i] == T_REG)
			ret += REG_REF_SIZE;
		else if (param[i] == T_IND)
			ret += IND_SIZE;
		else if (param[i] == T_DIR)
			ret += dir_as_addr ? IND_SIZE : DIR_SIZE;
	}
	return (ret);
}
