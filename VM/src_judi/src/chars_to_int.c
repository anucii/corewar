/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_to_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:01:41 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/14 17:06:59 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "judi.h"

unsigned int	chars_to_int(unsigned char *ptr)
{
	unsigned int	val;

	if (!ptr)
		return (0);
	val = ((unsigned int) ptr[0] << 24);
	val |= ((unsigned int) ptr[1] << 16);
	val |= ((unsigned int) ptr[2] << 8);
	val |= ((unsigned int) ptr[3]);
	return (val);
}
