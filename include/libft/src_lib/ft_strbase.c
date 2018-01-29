/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:18:13 by jgonthie          #+#    #+#             */
/*   Updated: 2017/07/20 13:35:11 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_conv_to_binary(unsigned long long int nbr, size_t size, char *s)
{
	unsigned int			n;
	size_t					len;

	len = 2;
	if (nbr / 2)
		s = ft_conv_to_binary(nbr / 2, size, s);
	if (s)
		len += ft_strlen(s);
	s = ft_realloc(s, len);
	n = nbr % 2;
	s[len - 2] = n + '0';
	s[len - 1] = '\0';
	return (s);
}

static int	ft_conv(char *binary, int block, int len)
{
	int		add;
	int		tmp;
	int		cnt;
	int		n;

	cnt = 0;
	n = 0;
	while (block-- > 0 && len >= 0)
	{
		add = 2;
		tmp = cnt;
		if (binary[len] == '1' && cnt == 0)
			n = 1;
		else if (binary[len] == '1' && cnt == 1)
			n += 2;
		else if (binary[len] == '1')
		{
			while (tmp-- > 1)
				add = 2 * add;
			n += add;
		}
		cnt++;
		len--;
	}
	return (n);
}

static char	*ft_makestr(char *base, char *binary, size_t size)
{
	size_t	block;
	char	*str;
	int		len;
	int		n;

	block = 0;
	len = 1;
	str = NULL;
	while (size /= 2)
		block++;
	while (binary[0] != '\0')
	{
		n = ft_conv(binary, block, ft_strlen(binary) - 1);
		if (ft_strlen(binary) < block)
			binary[0] = '\0';
		else
			binary[ft_strlen(binary) - block] = '\0';
		if (str)
			len = ft_strlen(str) + 1;
		str = ft_realloc(str, len);
		str[len - 1] = base[n];
		str[len] = '\0';
	}
	return (str);
}

char		*ft_strbase(unsigned long long int nbr, char *base)
{
	char					*binary;
	char					*tmp;
	char					*str;
	size_t					size;

	binary = NULL;
	tmp = NULL;
	str = NULL;
	size = ft_strlen(base);
	binary = ft_conv_to_binary(nbr, size, binary);
	if (size == 2)
		return (binary);
	tmp = ft_makestr(base, binary, size);
	str = ft_memalloc(ft_strlen(tmp));
	str = ft_reverse(str, tmp);
	ft_strdel(&binary);
	ft_strdel(&tmp);
	return (str);
}
