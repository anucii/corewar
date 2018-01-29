/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 20:12:31 by jgonthie          #+#    #+#             */
/*   Updated: 2016/11/24 14:30:27 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*ptr2;
	size_t			i;

	ptr = (unsigned char*)src;
	ptr2 = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		*(ptr2 + i) = *(ptr + i);
		if (*(ptr + i) == (unsigned char)c)
		{
			dst = (void*)ptr2;
			return (dst + i + 1);
		}
		i++;
	}
	return (NULL);
}
