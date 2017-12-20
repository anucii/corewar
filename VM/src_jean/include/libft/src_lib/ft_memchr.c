/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 20:15:10 by jgonthie          #+#    #+#             */
/*   Updated: 2016/11/21 10:03:56 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	void			*ptr2;
	size_t			i;

	ptr = (unsigned char*)s;
	ptr2 = NULL;
	i = 0;
	while (i < n && *(ptr + i) != (unsigned char)c)
		i++;
	if ((i < n) && (*(ptr + i) == (unsigned char)c))
	{
		ptr2 = (ptr + i);
		return (ptr2);
	}
	return (NULL);
}
