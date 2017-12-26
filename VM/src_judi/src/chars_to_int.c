/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_to_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:01:41 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/26 15:36:52 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "judi.h"

/*
**	chars_to_int reads a direct value on memory and converts it to a legit
**	unsigned int value
**	Parameters :
**	- mem : pointer on the beginning of the general memory space
**	- i : index of the first byte of the value to convert
**	- lg : boolean value set to TRUE if there is no IDX_MOD limitation of 
**	the memory accesses in the caller function
*/

unsigned int	chars_to_int(unsigned char *mem, unsigned int i, _Bool lg)
{
	unsigned int	val;
	unsigned int	mod;

	if (!mem)
		error_vm("chars_to_int() called with a null memory pointer");
	mod = lg ? MEM_SIZE : IDX_MOD;
	val = ((unsigned int) mem[i % mod] << 24);
	val |= ((unsigned int) mem[(i + 1) % mod] << 16);
	val |= ((unsigned int) mem[(i + 2) % mod] << 8);
	val |= ((unsigned int) mem[(i + 3) % mod]);
	return (val);
}
