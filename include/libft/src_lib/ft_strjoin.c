/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 19:10:26 by jgonthie          #+#    #+#             */
/*   Updated: 2017/01/09 16:58:56 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = NULL;
	if (s1 && s2)
	{
		if (!(new = (char*)malloc(sizeof(*new)
						* ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (NULL);
		while (s1[i])
		{
			new[i] = s1[i];
			i++;
		}
		while (s2[j])
			new[i++] = s2[j++];
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
