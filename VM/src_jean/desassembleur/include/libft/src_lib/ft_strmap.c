/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:08:56 by jgonthie          #+#    #+#             */
/*   Updated: 2016/11/23 18:19:37 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	size_t	len;
	char	*new;
	char	*str;

	len = 0;
	i = 0;
	str = NULL;
	if (s)
	{
		len = ft_strlen(s);
		str = (char*)s;
		if (!(new = (char*)malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (s[i])
		{
			new[i] = (f)(str[i]);
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
