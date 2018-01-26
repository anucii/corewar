/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 22:13:06 by jgonthie          #+#    #+#             */
/*   Updated: 2017/07/20 13:34:21 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_spec_prct(t_buff *buff, t_spec *spec, t_pft_flag *pft_flag)
{
	spec->spc_conv = ft_strdup("%");
	ft_checkflags(spec, pft_flag);
	ft_putspecinbuff(buff, spec);
}

static void	ft_lc(t_buff *b, t_spec *s, t_pft_flag *p, wchar_t result)
{
	s->spc_conv = ft_strnew(2);
	s->spc_conv[0] = result;
	s->tab_spec[0] = -1;
	if (!result)
	{
		s->tab_spec[1] -= 1;
		ft_checkflags(s, p);
		ft_putspecinbuff(b, s);
		b->len++;
		return ;
	}
}

static void	ft_c(t_buff *b, t_spec *s, t_pft_flag *p, int result)
{
	s->spc_conv = ft_strnew(2);
	s->spc_conv[0] = result;
	if (!result && s->tab_spec[1] > 1)
	{
		s->tab_spec[1] -= 1;
		ft_checkflags(s, p);
		ft_putspecinbuff(b, s);
		b->len++;
		return ;
	}
	if (s->tab_spec[0] >= 0)
	{
		s->tab_spec[0] = -1;
		ft_checkflags(s, p);
		ft_putspecinbuff(b, s);
		if (!result)
			b->len++;
		return ;
	}
	ft_checkflags(s, p);
	ft_putspecinbuff(b, s);
	if (!result)
		b->len++;
}

void		ft_spec_c(t_buff *b, t_spec *s, t_pft_flag *p, va_list ap)
{
	int		result;

	result = 0;
	if (s->spc == 'c' && s->tab_spec[9] == 1)
		s->spc = 'C';
	if (s->spc == '%')
		ft_spec_prct(b, s, p);
	else if (s->spc == 'c')
	{
		if (s->undefined == 1)
		{
			ft_checkflags(s, p);
			ft_putspecinbuff(b, s);
			return ;
		}
		result = va_arg(ap, int);
		ft_c(b, s, p, result);
	}
	else if (s->spc == 'C')
	{
		result = va_arg(ap, wchar_t);
		ft_lc(b, s, p, result);
		ft_strdel(&s->spc_conv);
		ft_unicode(b, s, result);
	}
}
