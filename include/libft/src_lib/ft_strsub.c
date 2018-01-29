/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:38:48 by jgonthie          #+#    #+#             */
/*   Updated: 2017/01/14 19:52:30 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*new;

	i = 0;
	j = 0;
	new = NULL;
	if (s)
	{
		if (!(new = (char*)malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (i < start)
			i++;
		while (len)
		{
			new[j] = s[i];
			i++;
			j++;
			len--;
		}
		new[j] = '\0';
		return (new);
	}
	return (NULL);
}
