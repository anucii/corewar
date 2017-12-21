/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 21:25:03 by jgonthie          #+#    #+#             */
/*   Updated: 2016/11/24 14:30:48 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*ptr2;
	size_t			i;

	i = 0;
	ptr = (unsigned char*)s1;
	ptr2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (*((unsigned char*)ptr + i) == *((unsigned char*)ptr2 + i)
			&& i + 1 < n)
		i++;
	if (n == i)
		return (0);
	return (*(ptr + i) - *(ptr2 + i));
}
