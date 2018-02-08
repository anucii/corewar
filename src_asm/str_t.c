/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 13:06:51 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/08 18:28:53 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Function created to help labelcall to get a way to retrieve the type
**	associated to a label without adding a parameter to its prototype (for
**	norm compliance purposes). Command types list :
**	- "1" : record the type send as parameter
**	- "-1" : reset the record to zero
**	- "0" (or any other value) : simply return the stored value, whatever the
**	content of the second parameter is
*/

#include "asm.h"

int	str_t(int cmd, int type)
{
	static int	record = 0;

	if (cmd == 1)
		record = type;
	else if (cmd == -1)
		record = 0;
	return (record);
}
