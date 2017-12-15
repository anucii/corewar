/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_to_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:01:41 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/15 15:20:14 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "judi.h"

/*
**	chars_to_int reads a direct value on memory and converts it to a legit
**	unsigned int value
**	Parameters :
**	- mem : pointer on the beginning of the general memory space
**	- i : index of the first byte of the value to convert
*/

unsigned int	chars_to_int(unsigned char *mem, unsigned int i)
{
	unsigned int	val;

	if (!mem)
		error_vm("chars_to_int() called with a null memory pointer");
	val = ((unsigned int) mem[i % MEM_SIZE] << 24);
	val |= ((unsigned int) mem[(i + 1) % MEM_SIZE] << 16);
	val |= ((unsigned int) mem[(i + 2) % MEM_SIZE] << 8);
	val |= ((unsigned int) mem[(i + 3) % MEM_SIZE]);
	return (val);
}
