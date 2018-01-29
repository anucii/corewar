/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 14:24:54 by jgonthie          #+#    #+#             */
/*   Updated: 2017/07/20 13:31:35 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putprefix(t_spec *spec, int index, char c)
{
	char	*tmp;

	tmp = NULL;
	if (index == 1 && spec->spc_conv[index + 2] != '\0')
	{
		spec->spc_conv[0] = c;
		tmp = ft_strdup(spec->spc_conv);
		ft_strdel(&spec->spc_conv);
		spec->spc_conv = ft_strjoin("0", tmp);
		ft_strdel(&tmp);
		return ;
	}
	spec->spc_conv[index - 2] = '0';
	spec->spc_conv[index - 1] = c;
}

void		ft_hash_x(t_spec *spec)
{
	char	*tmp;
	int		index;

	tmp = NULL;
	index = 0;
	if ((spec->spc_conv[0] == '0' && ft_strlen(spec->spc_conv) == 1) ||
			spec->spc_conv[0] == '\0')
		return ;
	while (spec->spc_conv[index] == ' ')
		index++;
	if (index > 0)
		ft_putprefix(spec, index, 'x');
	tmp = ft_strdup(spec->spc_conv);
	ft_strdel(&spec->spc_conv);
	spec->spc_conv = ft_strjoin("0x", tmp);
	ft_strdel(&tmp);
}

void		ft_hash_lx(t_spec *spec)
{
	char	*tmp;
	int		index;

	tmp = NULL;
	index = 0;
	if ((spec->spc_conv[0] == '0' && ft_strlen(spec->spc_conv) == 1) ||
			spec->spc_conv[0] == '\0')
		return ;
	while (spec->spc_conv[index] == ' ')
		index++;
	if (index > 0)
		ft_putprefix(spec, index, 'X');
	tmp = ft_strdup(spec->spc_conv);
	ft_strdel(&spec->spc_conv);
	spec->spc_conv = ft_strjoin("0X", tmp);
	ft_strdel(&tmp);
}

void		ft_hash_o(t_spec *spec)
{
	char	*tmp;
	int		index;

	tmp = NULL;
	index = 0;
	if (spec->spc_conv[0] == '\0' && spec->tab_spec[0] < 0)
		return ;
	if (spec->spc_conv[0] == ' ')
	{
		while (spec->spc_conv[index] == ' ')
			index++;
		spec->spc_conv[index - 1] = '0';
	}
	else if (spec->spc_conv[0] == '0')
		return ;
	else
	{
		tmp = ft_strdup(spec->spc_conv);
		ft_strdel(&spec->spc_conv);
		spec->spc_conv = ft_strjoin("0", tmp);
		ft_strdel(&tmp);
	}
}
