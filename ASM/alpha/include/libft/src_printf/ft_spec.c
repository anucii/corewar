/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 16:47:19 by jgonthie          #+#    #+#             */
/*   Updated: 2017/07/20 13:34:04 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_inipftflags(t_pft_flag *tab_pft_flags)
{
	tab_pft_flags[0] = &ft_prec_number;
	tab_pft_flags[1] = &ft_width_number;
	tab_pft_flags[2] = &ft_plus;
	tab_pft_flags[3] = &ft_minus;
	tab_pft_flags[4] = &ft_zero;
	tab_pft_flags[5] = &ft_space;
	tab_pft_flags[6] = &ft_hash_o;
	tab_pft_flags[7] = &ft_hash_x;
	tab_pft_flags[8] = &ft_hash_lx;
	tab_pft_flags[9] = &ft_prec_string;
}

static void	ft_inipftspec(t_pft_spec *tab_pft_spec)
{
	tab_pft_spec[0] = &ft_spec_d;
	tab_pft_spec[1] = &ft_spec_u;
	tab_pft_spec[2] = &ft_spec_o;
	tab_pft_spec[3] = &ft_spec_x;
	tab_pft_spec[4] = &ft_spec_c;
	tab_pft_spec[5] = &ft_spec_s;
	tab_pft_spec[6] = &ft_spec_p;
	tab_pft_spec[7] = &ft_spec_b;
}

void		ft_checkflags(t_spec *spec, t_pft_flag *tab_pft_flags)
{
	if (spec->tab_spec[0] >= 0 && (spec->spc != 's' &&
			spec->spc != 'S' && spec->spc != '%'))
		tab_pft_flags[0](spec);
	else if (spec->tab_spec[0] >= 0 && spec->spc != '%')
		tab_pft_flags[9](spec);
	if (spec->tab_spec[6] >= 0 && (spec->spc == 'o' || spec->spc == 'O'))
		tab_pft_flags[6](spec);
	if (spec->tab_spec[6] >= 0 && spec->spc == 'x')
		tab_pft_flags[7](spec);
	if (spec->tab_spec[6] >= 0 && spec->spc == 'X')
		tab_pft_flags[8](spec);
	if (spec->tab_spec[2] >= 0)
		tab_pft_flags[3](spec);
	if (spec->tab_spec[1] >= 0 && spec->tab_spec[2] < 0)
		tab_pft_flags[1](spec);
	if (spec->tab_spec[3] >= 0)
		tab_pft_flags[2](spec);
	if (spec->tab_spec[4] >= 0)
		tab_pft_flags[4](spec);
	if (spec->tab_spec[5] >= 0)
		tab_pft_flags[5](spec);
}

void		ft_spec(t_buff *buff, t_spec *spec, va_list ap)
{
	t_pft_spec		tab_pft_spec[8];
	t_pft_flag		tab_pft_flags[10];

	ft_inipftspec(tab_pft_spec);
	ft_inipftflags(tab_pft_flags);
	if (spec->spc == 'i' || spec->spc == 'd' || spec->spc == 'D')
		tab_pft_spec[0](buff, spec, tab_pft_flags, ap);
	else if (spec->spc == 'u' || spec->spc == 'U')
		tab_pft_spec[1](buff, spec, tab_pft_flags, ap);
	else if (spec->spc == 'o' || spec->spc == 'O')
		tab_pft_spec[2](buff, spec, tab_pft_flags, ap);
	else if (spec->spc == 'x' || spec->spc == 'X')
		tab_pft_spec[3](buff, spec, tab_pft_flags, ap);
	else if (spec->spc == 'c' || spec->spc == 'C' || spec->spc == '%')
		tab_pft_spec[4](buff, spec, tab_pft_flags, ap);
	else if (spec->spc == 's' || spec->spc == 'S')
		tab_pft_spec[5](buff, spec, tab_pft_flags, ap);
	else if (spec->spc == 'p')
		tab_pft_spec[6](buff, spec, tab_pft_flags, ap);
	else if (spec->spc == 'b')
		tab_pft_spec[7](buff, spec, tab_pft_flags, ap);
	ft_resetstruct(spec);
}
