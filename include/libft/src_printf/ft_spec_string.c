/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 15:03:02 by jgonthie          #+#    #+#             */
/*   Updated: 2017/07/20 13:34:56 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_lenwchart(wchar_t *uni)
{
	int		len_uni;
	int		index;
	int		len;
	char	*bit;

	len_uni = 0;
	index = 0;
	while (uni[index])
	{
		bit = ft_strbase(uni[index], "01");
		len = ft_strlen(bit);
		ft_strdel(&bit);
		if (len <= 7 || (uni[index] <= 255 && MB_CUR_MAX != 4))
			len_uni += 1;
		else if (MB_CUR_MAX != 4)
			return (-1);
		else if (len > 7 && len <= 11 && MB_CUR_MAX == 4)
			len_uni += 2;
		else if (len > 11 && len <= 16 && MB_CUR_MAX == 4)
			len_uni += 3;
		else if (len > 16 && MB_CUR_MAX == 4)
			len_uni += 4;
		index++;
	}
	return (len_uni);
}

static void		ft_spec_ls(t_buff *b, t_spec *s, wchar_t *ws)
{
	int		len_uni;
	int		index;
	int		prec;

	len_uni = ft_lenwchart(ws);
	index = -1;
	prec = 0;
	if (s->tab_spec[0] == 0)
		len_uni = 0;
	if (s->tab_spec[1] > len_uni && s->tab_spec[2] == -1)
		ft_width_string(b, s, len_uni);
	if (s->tab_spec[0] > 0 && s->tab_spec[1] > s->tab_spec[0])
		ft_precandwidth(b, s, ws);
	while (ws[++index] && s->tab_spec[0] != 0 && b->len != -1)
	{
		if (s->tab_spec[0] > 0)
		{
			prec += ft_prec_wchart(ws[index]);
			if (prec > s->tab_spec[0])
				break ;
		}
		ft_unicode(b, s, ws[index]);
	}
	if (s->tab_spec[1] > len_uni && s->tab_spec[2] == 1 && b->len != -1)
		ft_width_string(b, s, len_uni);
}

void			ft_spec_s(t_buff *b, t_spec *s, t_pft_flag *p, va_list ap)
{
	wchar_t	*result_ws;
	char	*result_s;

	result_s = NULL;
	if (s->spc == 's' && s->tab_spec[9] == -1)
	{
		result_s = va_arg(ap, char*);
		if (!result_s)
			s->spc_conv = ft_strdup("(null)");
		else
			s->spc_conv = ft_strdup(result_s);
		ft_checkflags(s, p);
		ft_putspecinbuff(b, s);
	}
	else
	{
		result_ws = va_arg(ap, wchar_t*);
		if (!result_ws)
		{
			s->spc_conv = ft_strdup("(null)");
			ft_putspecinbuff(b, s);
			return ;
		}
		ft_spec_ls(b, s, result_ws);
	}
}
