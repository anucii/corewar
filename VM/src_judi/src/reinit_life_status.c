/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinit_life_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 18:42:20 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/14 18:43:58 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "judi.h"

void reinit_life_status(t_proc *p)
{
	if (!p)
		error_vm("Life status reinitialization called on a null proc pointer");
	p->life.status = 0;
	p->life.last = 0; // to suppress
	p->life.player = 0;
}
