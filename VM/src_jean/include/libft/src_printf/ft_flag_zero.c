/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:51:11 by jgonthie          #+#    #+#             */
/*   Updated: 2017/07/20 13:32:13 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_undefined_p(t_spec *spec)
{
	char	*tmp;

	tmp = NULL;
	if (spec->spc == 'p')
	{
		tmp = ft_strchr(spec->spc_conv, 'x');
		*tmp = '0';
		spec->spc_conv[1] = 'x';
	}
}

static int	ft_zeroandsymbol(t_spec *spec, int index)
{
	char	*tmp;

	tmp = NULL;
	while (spec->spc_conv[++index] == ' ')
		spec->spc_conv[index] = '0';
	if (spec->spc_conv[index] == '+' && index != 0)
	{
		spec->spc_conv[0] = '+';
		spec->spc_conv[index] = '0';
	}
	else if (spec->spc_conv[index] == '-' && index != 0)
	{
		spec->spc_conv[0] = '-';
		spec->spc_conv[index] = '0';
	}
	if ((tmp = ft_strchr(spec->spc_conv, '-')))
	{
		*tmp = '0';
		spec->spc_conv[0] = '-';
	}
	ft_undefined_p(spec);
	return (index);
}

void		ft_zero(t_spec *spec)
{
	int		index;

	index = -1;
	if (spec->spc_conv[0] == '+')
		index++;
	if (spec->tab_spec[5] >= 0 && (spec->spc_conv[0] != '-' ||
				spec->spc_conv[0] != '+'))
		index++;
	if (spec->tab_spec[0] > 0 && (spec->tab_spec[0] < spec->tab_spec[1]))
		return ;
	if (spec->tab_spec[1] == (int)ft_strlen(spec->spc_conv) &&
			!ft_isalpha(spec->spc_conv[0]))
		index = ft_zeroandsymbol(spec, index);
	if (spec->tab_spec[4] > 0 && (spec->spc == 'x' || spec->spc == 'X')
			&& spec->tab_spec[1] >= 4 && spec->tab_spec[2] < 0
			&& spec->tab_spec[6] > 0)
	{
		spec->spc_conv[0] = '0';
		spec->spc_conv[1] = 'x';
		index = 2;
		while (spec->spc_conv[index] == '0')
			index++;
		spec->spc_conv[index] = '0';
	}
}
