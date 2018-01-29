/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkspec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 10:39:59 by jgonthie          #+#    #+#             */
/*   Updated: 2017/07/20 13:31:24 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_if_prec(t_spec *spec, char *format, int indx_frmt)
{
	char	*width;
	int		start;
	int		len;

	len = 1;
	width = NULL;
	start = indx_frmt + 1;
	if (format[indx_frmt] == '.')
	{
		indx_frmt++;
		if (!ft_isdigit(format[indx_frmt]))
		{
			spec->tab_spec[0] = 0;
			return (indx_frmt - 1);
		}
		while (ft_isdigit(format[++indx_frmt]) &&
				format[indx_frmt] != '\0')
			len++;
		width = ft_strsub(format, start, len);
		spec->tab_spec[0] = ft_atoi(width);
		ft_strdel(&width);
		if (!ft_isdigit(format[indx_frmt]))
			indx_frmt--;
	}
	return (indx_frmt);
}

static int	ft_if_width(t_spec *spec, char *format, int indx_frmt)
{
	char	*width;
	int		start;
	int		len;

	len = 0;
	width = NULL;
	start = indx_frmt;
	if (ft_isdigit(format[indx_frmt]) && format[indx_frmt] != '0'
			&& format[indx_frmt - 1] != '.')
	{
		while (ft_isdigit(format[indx_frmt]) && format[indx_frmt])
		{
			indx_frmt++;
			len++;
		}
		width = ft_strsub(format, start, len);
		spec->tab_spec[1] = ft_atoi(width);
		ft_strdel(&width);
		indx_frmt--;
	}
	return (indx_frmt);
}

static void	ft_if_flags(t_spec *spec, char *format, int indx_frmt)
{
	if (format[indx_frmt] == '-')
		spec->tab_spec[2] = 1;
	if (format[indx_frmt] == '+')
		spec->tab_spec[3] = 1;
	if (format[indx_frmt] == '0' && !ft_isdigit(format[indx_frmt - 1])
			&& format[indx_frmt - 1] != '.')
		spec->tab_spec[4] = 1;
	if (format[indx_frmt] == ' ')
		spec->tab_spec[5] = 1;
	if (format[indx_frmt] == '#')
		spec->tab_spec[6] = 1;
}

static int	ft_if_length(t_spec *spec, char *format, int indx_frmt)
{
	if (format[indx_frmt] == 'h')
	{
		if (format[indx_frmt + 1] == 'h')
		{
			spec->tab_spec[8] = 1;
			indx_frmt++;
		}
		else
			spec->tab_spec[7] = 1;
	}
	if (format[indx_frmt] == 'l')
	{
		if (format[indx_frmt + 1] == 'l')
		{
			spec->tab_spec[10] = 1;
			indx_frmt++;
		}
		else
			spec->tab_spec[9] = 1;
	}
	if (format[indx_frmt] == 'j')
		spec->tab_spec[11] = 1;
	if (format[indx_frmt] == 'z')
		spec->tab_spec[12] = 1;
	return (indx_frmt);
}

int			ft_checkspec(t_spec *spec, char *frmt, int idx_frmt)
{
	while (!ft_strchr("sScCidDuUoOxXpb%", frmt[idx_frmt]) && frmt[idx_frmt])
	{
		if ((!ft_strchr(".+0-# hljz", frmt[idx_frmt]) &&
			!ft_isdigit(frmt[idx_frmt])) && frmt[idx_frmt])
		{
			spec->spc_conv = ft_strnew(2);
			spec->spc_conv[0] = frmt[idx_frmt];
			spec->spc = 'c';
			spec->undefined = 1;
			return (idx_frmt);
		}
		idx_frmt = ft_if_width(spec, frmt, idx_frmt);
		idx_frmt = ft_if_prec(spec, frmt, idx_frmt);
		ft_if_flags(spec, frmt, idx_frmt);
		idx_frmt = ft_if_length(spec, frmt, idx_frmt);
		idx_frmt++;
	}
	spec->spc = frmt[idx_frmt];
	return (idx_frmt);
}
