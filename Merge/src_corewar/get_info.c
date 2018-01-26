/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 19:21:06 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/29 19:27:38 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Store the t_info structure address when called with a non-NULL pointer,
**	simply return the pointed pointer otherwise.
**	MUST BE first initialized from the main function!
*/

t_info	*get_info(t_info **p_info)
{
	static t_info	**addr = NULL;

	if (p_info)
		addr = p_info;
	return (addr ? *addr : NULL);
}
