/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 16:04:29 by jgonthie          #+#    #+#             */
/*   Updated: 2017/07/20 13:34:40 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_undefined(t_buff *b, t_spec *s, char *tmp)
{
	if (s->tab_spec[0] == 0)
	{
		s->spc_conv = ft_strdup("0x");
		ft_putspecinbuff(b, s);
		ft_strdel(&tmp);
		return ;
	}
	s->spc_conv = ft_strjoin("0x", tmp);
}

void		ft_spec_p(t_buff *b, t_spec *s, t_pft_flag *p, va_list ap)
{
	void	*result;
	char	*tmp;

	result = va_arg(ap, void*);
	tmp = ft_strbase((unsigned long int)result, "0123456789abcdef");
	if (s->tab_spec[4] == -1 && s->tab_spec[0] != 0)
		ft_undefined(b, s, tmp);
	else
	{
		if (s->tab_spec[4] == 1)
			s->spc_conv = ft_strjoin("0x", tmp);
		else
		{
			s->spc_conv = ft_strdup("0x");
			ft_putspecinbuff(b, s);
			ft_strdel(&s->spc_conv);
			s->spc_conv = ft_strdup(tmp);
		}
	}
	ft_checkflags(s, p);
	ft_putspecinbuff(b, s);
	ft_strdel(&tmp);
}
