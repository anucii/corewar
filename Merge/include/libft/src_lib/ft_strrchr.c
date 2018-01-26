/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 02:18:49 by jgonthie          #+#    #+#             */
/*   Updated: 2016/11/24 17:17:46 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (len)
	{
		if (s[len] == (char)c)
			return ((char*)s + len);
		len--;
		if (s[len] == (char)c)
			return ((char*)s + len);
	}
	if (c == '\0')
		return ((char*)s + len);
	return (NULL);
}
