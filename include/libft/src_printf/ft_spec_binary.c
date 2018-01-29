/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 16:17:55 by jgonthie          #+#    #+#             */
/*   Updated: 2017/07/20 13:34:12 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_spec_b(t_buff *b, t_spec *s, t_pft_flag *p, va_list ap)
{
	long long int		result;

	result = 0;
	if (s->tab_spec[7] == 1)
		result = (short int)va_arg(ap, int);
	else if (s->tab_spec[8] == 1)
		result = (signed char)va_arg(ap, int);
	else if (s->tab_spec[9] == 1)
		result = va_arg(ap, long int);
	else if (s->tab_spec[10] == 1)
		result = va_arg(ap, long long int);
	else if (s->tab_spec[11] == 1)
		result = va_arg(ap, intmax_t);
	else if (s->tab_spec[12] == 1)
		result = va_arg(ap, size_t);
	else if (s->spc == 'b')
		result = va_arg(ap, int);
	if (result < 0)
		result *= -1;
	s->spc_conv = ft_strbase(result, "01");
	ft_putspecinbuff(b, s);
	ft_checkflags(s, p);
}
