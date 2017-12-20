/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:30:50 by jgonthie          #+#    #+#             */
/*   Updated: 2016/11/24 17:29:26 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] == s2[i] && i < n)
		{
			if (s1[i] == '\0' && s2[i] == '\0')
				return (1);
			i++;
		}
		if (ft_strncmp(s1, s2, n) == 0)
			return (1);
	}
	return (0);
}
