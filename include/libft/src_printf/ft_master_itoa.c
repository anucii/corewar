/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_master_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 19:39:35 by jgonthie          #+#    #+#             */
/*   Updated: 2017/07/20 13:32:36 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_master_itoa(unsigned long long int n)
{
	unsigned long long int	nbr;
	char					*str_nb;
	int						len;

	len = 2;
	nbr = n;
	while (nbr /= 10)
		len++;
	if (!(str_nb = (char*)malloc(len)))
		return (NULL);
	len--;
	str_nb[len] = '\0';
	while (--len > -1)
	{
		str_nb[len] = n % 10 + '0';
		n /= 10;
	}
	return (str_nb);
}
