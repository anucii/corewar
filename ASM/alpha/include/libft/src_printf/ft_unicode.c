/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 14:24:59 by jgonthie          #+#    #+#             */
/*   Updated: 2017/07/20 13:35:49 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_mask3(t_buff *buff, t_spec *spec, unsigned int value)
{
	t_unicode	unicode;

	spec->spc_conv = ft_strnew(5);
	unicode.mask = 4034953344;
	unicode.o4 = (value << 26) >> 26;
	unicode.o3 = ((value >> 6) << 26) >> 26;
	unicode.o2 = ((value >> 12) << 26) >> 26;
	unicode.o1 = ((value >> 18) << 29) >> 29;
	unicode.octet = (unicode.mask >> 24) | unicode.o1;
	spec->spc_conv[0] = unicode.octet;
	unicode.octet = ((unicode.mask << 8) >> 24) | unicode.o2;
	spec->spc_conv[1] = unicode.octet;
	unicode.octet = ((unicode.mask << 16) >> 24) | unicode.o3;
	spec->spc_conv[2] = unicode.octet;
	unicode.octet = ((unicode.mask << 24) >> 24) | unicode.o4;
	spec->spc_conv[3] = unicode.octet;
	ft_putspecinbuff(buff, spec);
}

static void		ft_mask2(t_buff *buff, t_spec *spec, unsigned int value)
{
	t_unicode	unicode;

	spec->spc_conv = ft_strnew(4);
	unicode.mask = 14712960;
	unicode.o3 = (value << 26) >> 26;
	unicode.o2 = ((value >> 6) << 26) >> 26;
	unicode.o1 = ((value >> 12) << 28) >> 28;
	unicode.octet = (unicode.mask >> 16) | unicode.o1;
	spec->spc_conv[0] = unicode.octet;
	unicode.octet = ((unicode.mask << 16) >> 24) | unicode.o2;
	spec->spc_conv[1] = unicode.octet;
	unicode.octet = ((unicode.mask << 24) >> 24) | unicode.o3;
	spec->spc_conv[2] = unicode.octet;
	ft_putspecinbuff(buff, spec);
}

static void		ft_mask1(t_buff *buff, t_spec *spec, unsigned int value)
{
	t_unicode	unicode;

	spec->spc_conv = ft_strnew(3);
	unicode.mask = 49280;
	unicode.o2 = (value << 26) >> 26;
	unicode.o1 = ((value >> 6) << 27) >> 27;
	unicode.octet = (unicode.mask >> 8) | unicode.o1;
	spec->spc_conv[0] = unicode.octet;
	unicode.octet = ((unicode.mask << 24) >> 24) | unicode.o2;
	spec->spc_conv[1] = unicode.octet;
	ft_putspecinbuff(buff, spec);
}

void			ft_unicode(t_buff *buff, t_spec *spec, wchar_t result)
{
	char			*bit;
	unsigned int	value;
	size_t			len_bit;

	bit = ft_strbase(result, "01");
	value = result;
	len_bit = ft_strlen(bit);
	ft_strdel(&bit);
	if (len_bit <= 7 || (result <= 255 && MB_CUR_MAX != 4))
	{
		spec->spc_conv = ft_strnew(2);
		spec->spc_conv[0] = (unsigned char)result;
		ft_putspecinbuff(buff, spec);
		ft_strdel(&spec->spc_conv);
		return ;
	}
	if (MB_CUR_MAX != 4)
		buff->len = -1;
	else if (len_bit > 7 && len_bit <= 11 && MB_CUR_MAX == 4)
		ft_mask1(buff, spec, value);
	else if (len_bit > 11 && len_bit <= 16 && MB_CUR_MAX == 4)
		ft_mask2(buff, spec, value);
	else if (len_bit > 16 && MB_CUR_MAX == 4)
		ft_mask3(buff, spec, value);
	ft_strdel(&spec->spc_conv);
}
