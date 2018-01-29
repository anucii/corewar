/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:34:01 by jgonthie          #+#    #+#             */
/*   Updated: 2017/07/20 13:33:21 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reverse(char *copy, char *str)
{
	int		len;
	int		i;

	len = ft_strlen(str);
	i = 0;
	copy[len] = '\0';
	len--;
	while (str[i])
	{
		copy[len] = str[i];
		i++;
		len--;
	}
	return (copy);
}
