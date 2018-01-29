/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:07:16 by jgonthie          #+#    #+#             */
/*   Updated: 2016/11/24 17:09:38 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				i;
	size_t			len;
	char			*new;
	char			*str;

	i = 0;
	str = NULL;
	if (s)
	{
		str = (char*)s;
		len = ft_strlen(str);
		if (!(new = (char*)malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (str[i])
		{
			new[i] = (*f)(i, str[i]);
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
