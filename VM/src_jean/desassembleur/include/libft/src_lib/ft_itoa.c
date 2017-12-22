/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 09:35:11 by jgonthie          #+#    #+#             */
/*   Updated: 2016/12/27 11:36:13 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_if_itoa_neg(int *n, int *neg, int *len)
{
	if (*n < 0)
	{
		*neg = 1;
		*len += 1;
		*n *= -1;
	}
}

char			*ft_itoa(int n)
{
	char	*str_nb;
	int		len;
	int		neg;
	int		nbr;

	len = 2;
	neg = 0;
	nbr = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	while (nbr /= 10)
		len++;
	ft_if_itoa_neg(&n, &neg, &len);
	if (!(str_nb = (char*)malloc(len)))
		return (NULL);
	len--;
	str_nb[len] = '\0';
	while (--len > -1)
	{
		str_nb[len] = n % 10 + '0';
		n /= 10;
	}
	if (neg == 1)
		str_nb[0] = '-';
	return (str_nb);
}
