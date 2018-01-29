/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_nomber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 16:16:28 by jgonthie          #+#    #+#             */
/*   Updated: 2017/07/20 13:34:29 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_conv(t_spec *spec, long long int result)
{
	char			*tmp;

	tmp = NULL;
	if (result < 0)
	{
		result *= -1;
		tmp = ft_master_itoa(result);
		spec->spc_conv = ft_strjoin("-", tmp);
		ft_strdel(&tmp);
	}
	else
		spec->spc_conv = ft_master_itoa(result);
}

void			ft_spec_x(t_buff *b, t_spec *s, t_pft_flag *p, va_list ap)
{
	unsigned long long int	result;

	result = 0;
	if (s->tab_spec[7] == 1)
		result = (unsigned short int)va_arg(ap, unsigned long int);
	else if (s->tab_spec[8] == 1)
		result = (unsigned char)va_arg(ap, unsigned int);
	else if (s->tab_spec[9] == 1)
		result = va_arg(ap, unsigned long int);
	else if (s->tab_spec[10] == 1)
		result = va_arg(ap, unsigned long long int);
	else if (s->tab_spec[11] == 1)
		result = va_arg(ap, uintmax_t);
	else if (s->tab_spec[12] == 1)
		result = va_arg(ap, size_t);
	else
		result = va_arg(ap, unsigned int);
	if (s->spc == 'x')
		s->spc_conv = ft_strbase(result, "0123456789abcdef");
	if (s->spc == 'X')
		s->spc_conv = ft_strbase(result, "0123456789ABCDEF");
	ft_checkflags(s, p);
	ft_putspecinbuff(b, s);
}

void			ft_spec_o(t_buff *b, t_spec *s, t_pft_flag *p, va_list ap)
{
	unsigned long long int	result;

	result = 0;
	if (s->tab_spec[7] == 1 && s->spc != 'O')
		result = (unsigned short int)va_arg(ap, unsigned long int);
	else if (s->tab_spec[8] == 1 && s->spc != 'O')
		result = (unsigned char)va_arg(ap, unsigned int);
	else if (s->tab_spec[9] == 1)
		result = va_arg(ap, unsigned long int);
	else if (s->tab_spec[10] == 1)
		result = va_arg(ap, unsigned long long int);
	else if (s->tab_spec[11] == 1)
		result = va_arg(ap, uintmax_t);
	else if (s->tab_spec[12] == 1)
		result = va_arg(ap, size_t);
	else if (s->spc == 'o')
		result = va_arg(ap, unsigned int);
	else if (s->spc == 'O')
		result = va_arg(ap, unsigned long int);
	s->spc_conv = ft_strbase(result, "01234567");
	ft_checkflags(s, p);
	ft_putspecinbuff(b, s);
}

void			ft_spec_u(t_buff *b, t_spec *s, t_pft_flag *p, va_list ap)
{
	unsigned long long int	result;

	result = 0;
	if (s->tab_spec[7] == 1 && s->spc != 'U')
		result = (unsigned short int)va_arg(ap, unsigned long int);
	else if (s->tab_spec[8] == 1 && s->spc != 'U')
		result = (unsigned char)va_arg(ap, unsigned int);
	else if (s->tab_spec[9] == 1)
		result = va_arg(ap, unsigned long int);
	else if (s->tab_spec[10] == 1)
		result = va_arg(ap, unsigned long long int);
	else if (s->tab_spec[11] == 1)
		result = va_arg(ap, uintmax_t);
	else if (s->tab_spec[12] == 1)
		result = va_arg(ap, size_t);
	else if (s->spc == 'u')
		result = va_arg(ap, unsigned int);
	else if (s->spc == 'U')
		result = va_arg(ap, unsigned long int);
	s->spc_conv = ft_master_itoa(result);
	ft_checkflags(s, p);
	ft_putspecinbuff(b, s);
}

void			ft_spec_d(t_buff *b, t_spec *s, t_pft_flag *p, va_list ap)
{
	long long int		result;

	result = 0;
	if (s->tab_spec[7] == 1 && s->spc != 'D')
		result = (short int)va_arg(ap, int);
	else if (s->tab_spec[8] == 1 && s->spc != 'D')
		result = (signed char)va_arg(ap, int);
	else if (s->tab_spec[9] == 1)
		result = va_arg(ap, long int);
	else if (s->tab_spec[10] == 1)
		result = va_arg(ap, long long int);
	else if (s->tab_spec[11] == 1)
		result = va_arg(ap, intmax_t);
	else if (s->tab_spec[12] == 1)
		result = va_arg(ap, size_t);
	else if (s->spc == 'i' || s->spc == 'd')
		result = va_arg(ap, int);
	else if (s->spc == 'D')
		result = va_arg(ap, long int);
	ft_conv(s, result);
	ft_checkflags(s, p);
	ft_putspecinbuff(b, s);
}
