/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinit_life_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 18:42:20 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/28 14:39:04 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "judi.h"

void	reinit_life_status(t_proc **ptr_proc)
{
	if (!(ptr_proc && *ptr_proc))
		return ;
	(*ptr_proc)->life.status = 0;
	(*ptr_proc)->life.last = 0;
	(*ptr_proc)->life.player = 0;
}
