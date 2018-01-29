/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_deci.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 13:13:31 by jgonthie          #+#    #+#             */
/*   Updated: 2018/01/03 18:17:34 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crack.h"

static char	ft_check_letter(char letter)
{
	if (letter == 'a' || letter == 'A')
		return ('0');
	if (letter == 'b' || letter == 'B')
		return ('1');
	if (letter == 'c' || letter == 'C')
		return ('2');
	if (letter == 'd' || letter == 'D')
		return ('3');
	if (letter == 'e' || letter == 'E')
		return ('4');
	if (letter == 'f' || letter == 'F')
		return ('5');
	return (0);
}

static int	ft_conv(char c, int base, int p)
{
	long long int	nb;
	char			buffer[3];

	ft_bzero(buffer, 3);
	if (ft_isdigit(c))
		buffer[0] = c;
	else
	{
		buffer[0] = '1';
		buffer[1] = ft_check_letter(c);
	}
	nb = ft_atoi(buffer);
	nb = nb * pow(base, p);
	return (nb);
}

char		*ft_to_deci(char *s, char *base)
{
	char			*tmp;
	long long int	conv;
	int				index;
	int				size;
	int				len;

	conv = 0;
	index = -1;
	len = ft_strlen(s);
	size = ft_strlen(base);
	if (len == 0 || s == NULL || base == NULL)
		return (NULL);
	tmp = ft_memalloc(len + 1);
	tmp = ft_reverse(tmp, s);
	while (++index < len)
	{
		conv += ft_conv(tmp[index], size, index);
	}
	ft_strdel(&tmp);
	return (ft_itoa(conv));
}
