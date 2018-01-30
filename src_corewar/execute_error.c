/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 18:04:28 by jdaufin           #+#    #+#             */
/*   Updated: 2018/01/30 17:44:33 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	execute_error(t_proc *proc, int *param, unsigned int j)
{
	t_info *info;

	info = get_info(NULL);
	if (info->opt[3] && info->opt[4] && !info->opt[0])
		ft_printf(" [EPIC FAIL]");
	proc->pc = (proc->pc + j) % MEM_SIZE;
	free(param);
}
