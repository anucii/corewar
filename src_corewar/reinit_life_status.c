/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinit_life_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 18:42:20 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/08 14:02:55 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	reinit_life_status(t_proc **ptr_proc)
{
	if (!(ptr_proc && *ptr_proc))
		return ;
	(*ptr_proc)->life.status = 0;
	(*ptr_proc)->life.player = 0;
	(*ptr_proc)->life.cur = 0;
}
