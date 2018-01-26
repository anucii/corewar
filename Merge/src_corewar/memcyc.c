/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:37:41 by jgonthie          #+#    #+#             */
/*   Updated: 2018/01/09 16:56:44 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	*memcyc(void *dst, const void *src, size_t n, t_proc *p)
{
	size_t	i;

	i = 0;
	dst = ft_memalloc(sizeof(unsigned char) * 12);
	while (i < n)
	{
		((char*)dst)[i] = ((char*)src)[(p->pc + i) % MEM_SIZE];
		i++;
	}
	return (dst);
}
