/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 19:36:05 by jgonthie          #+#    #+#             */
/*   Updated: 2016/11/24 19:15:01 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*new;

	i = 0;
	j = 0;
	new = NULL;
	if (s)
	{
		len = ft_strlen(s);
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
			len--;
		if (s[i] == '\0')
			i = 0;
		if (!(new = (char*)malloc(sizeof(*new) * (len - i + 1))))
			return (NULL);
		while (i < len)
			new[j++] = s[i++];
		new[j] = '\0';
		return (new);
	}
	return (NULL);
}
