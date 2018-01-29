/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 10:57:05 by jgonthie          #+#    #+#             */
/*   Updated: 2017/07/22 15:48:12 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	int		cnt;

	i = 0;
	if (little[0] == '\0')
		return ((char*)big);
	while (big[i])
	{
		j = 0;
		if (big[i] == little[j])
		{
			cnt = i;
			while (big[cnt] == little[j])
			{
				if (little[j + 1] == '\0')
					return ((char*)big + cnt - j);
				cnt++;
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
