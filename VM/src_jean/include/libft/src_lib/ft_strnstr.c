/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 03:52:11 by jgonthie          #+#    #+#             */
/*   Updated: 2016/11/24 14:40:38 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;
	size_t		cnt;

	i = 0;
	if (!s2[0])
		return ((char*)s1);
	while (s1[i] && i < n)
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			cnt = i;
			while (s1[cnt] == s2[j] && cnt < n)
			{
				if (s2[j + 1] == '\0')
					return ((char*)s1 + cnt - j);
				cnt++;
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
