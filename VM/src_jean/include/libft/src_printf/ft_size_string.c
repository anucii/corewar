/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 13:39:10 by jgonthie          #+#    #+#             */
/*   Updated: 2017/07/20 13:33:47 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_prec_wchart(wchar_t uni)
{
	int		len_uni;
	int		len;
	char	*bit;

	len_uni = 0;
	bit = ft_strbase(uni, "01");
	len = ft_strlen(bit);
	ft_strdel(&bit);
	if (len <= 7 || (uni <= 255 && MB_CUR_MAX != 4))
		len_uni += 1;
	else if (MB_CUR_MAX != 4)
		return (-1);
	else if (len > 7 && len <= 11 && MB_CUR_MAX == 4)
		len_uni += 2;
	else if (len > 11 && len <= 16 && MB_CUR_MAX == 4)
		len_uni += 3;
	else if (len > 16 && MB_CUR_MAX == 4)
		len_uni += 4;
	return (len_uni);
}

void		ft_precandwidth(t_buff *b, t_spec *s, wchar_t *uni)
{
	int		index;
	int		prec;
	int		tmp;

	index = 0;
	prec = 0;
	tmp = 0;
	while (tmp <= s->tab_spec[0])
	{
		prec = tmp;
		tmp += ft_prec_wchart(uni[index]);
		index++;
	}
	while (prec < s->tab_spec[1])
	{
		if (s->tab_spec[4] == -1)
			ft_putinbuff(b, " ", 0);
		else
			ft_putinbuff(b, "0", 0);
		prec++;
	}
}

void		ft_width_string(t_buff *b, t_spec *s, int len_uni)
{
	while (s->tab_spec[1] > len_uni)
	{
		if (s->tab_spec[4] == -1)
			ft_putinbuff(b, " ", 0);
		else
			ft_putinbuff(b, "0", 0);
		s->tab_spec[1] -= 1;
	}
}
