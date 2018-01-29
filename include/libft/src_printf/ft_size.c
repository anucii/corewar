/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 16:53:55 by jgonthie          #+#    #+#             */
/*   Updated: 2017/07/20 13:33:33 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_prec_pointer(t_spec *spec)
{
	char	*tmp;

	tmp = NULL;
	if ((size_t)spec->tab_spec[0] == ft_strlen(spec->spc_conv) &&
			spec->spc_conv[1] != 'x' && spec->spc == 'p')
	{
		tmp = ft_strchr(spec->spc_conv, 'x');
		*tmp = '0';
		tmp = ft_strdup(spec->spc_conv);
		ft_strdel(&spec->spc_conv);
		spec->spc_conv = ft_strjoin("0x", tmp);
		ft_strdel(&tmp);
	}
}

static void	ft_prec_number_2(t_spec *spec, int len, int len_spec, int neg)
{
	char	*tmp;

	len = spec->tab_spec[0] + neg;
	tmp = ft_strnew(len + 1);
	if (neg == 1)
	{
		tmp[0] = '-';
		spec->spc_conv[0] = '0';
	}
	while (len_spec >= 0)
	{
		tmp[len] = spec->spc_conv[len_spec];
		len_spec--;
		len--;
	}
	while (len - neg >= 0)
	{
		tmp[len] = '0';
		len--;
	}
	ft_strdel(&spec->spc_conv);
	spec->spc_conv = ft_strdup(tmp);
	ft_strdel(&tmp);
}

void		ft_prec_number(t_spec *spec)
{
	int		neg;
	int		len_spec;
	int		len;

	neg = 0;
	len = 0;
	len_spec = ft_strlen(spec->spc_conv);
	if (spec->tab_spec[0] <= 0 && spec->spc_conv[0] == '0')
	{
		ft_memset(spec->spc_conv, '\0', len_spec);
		return ;
	}
	if (spec->spc_conv[0] == '-')
		neg = 1;
	if ((spec->tab_spec[0] > len_spec && neg == 0)
			|| (spec->tab_spec[0] > (len_spec - 1) && neg == 1))
		ft_prec_number_2(spec, len, len_spec, neg);
	if (spec->spc == 'p')
		ft_prec_pointer(spec);
}

void		ft_prec_string(t_spec *spec)
{
	int			index;
	int			len;

	index = 0;
	len = 0;
	if (spec->tab_spec[0] == 0)
	{
		while (spec->spc_conv[index])
		{
			spec->spc_conv[index] = '\0';
			index++;
		}
	}
	else if (spec->tab_spec[0] < (int)ft_strlen(spec->spc_conv))
	{
		len = ft_strlen(spec->spc_conv);
		while (len >= spec->tab_spec[0])
		{
			spec->spc_conv[len] = '\0';
			len--;
		}
	}
}

void		ft_width_number(t_spec *spec)
{
	char	*tmp;
	int		len_spec;
	int		len;

	len = spec->tab_spec[1];
	tmp = NULL;
	len_spec = ft_strlen(spec->spc_conv);
	if (spec->tab_spec[1] > len_spec)
	{
		tmp = ft_strnew(len + 1);
		while (len_spec >= 0)
		{
			tmp[len] = spec->spc_conv[len_spec];
			len--;
			len_spec--;
		}
		while (len >= 0)
		{
			tmp[len] = ' ';
			len--;
		}
		ft_strdel(&spec->spc_conv);
		spec->spc_conv = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
}
