/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 10:57:13 by jgonthie          #+#    #+#             */
/*   Updated: 2017/09/12 13:28:36 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *str;

	str = (void*)malloc(sizeof(void*) * size + 1);
	if (str == NULL)
	{
		ft_putstr("MALLOC FAILED\n");
		exit(0);
	}
	ft_bzero(str, size + 1);
	return (str);
}
