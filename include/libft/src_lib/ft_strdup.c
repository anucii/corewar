/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:42:16 by jgonthie          #+#    #+#             */
/*   Updated: 2017/09/25 17:32:21 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		len;

	copy = NULL;
	len = 0;
	if (s1)
	{
		len = ft_strlen(s1);
		if (!(copy = (char*)malloc(sizeof(*s1) * len + 1)))
		{
			ft_putstr("MALLOC FAILED\n");
			exit(0);
		}
		ft_strcpy(copy, s1);
	}
	return (copy);
}
