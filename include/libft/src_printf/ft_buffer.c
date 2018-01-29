/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 10:21:40 by jgonthie          #+#    #+#             */
/*   Updated: 2017/07/20 13:30:58 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putspecinbuff(t_buff *buff, t_spec *spec)
{
	int		len;
	int		index;

	len = ft_strlen(spec->spc_conv);
	index = -1;
	if (buff->len == 0)
		buff->sentence = ft_strnew(BUFF_SIZE_P);
	if (buff->len + len >= BUFF_SIZE_P * buff->count)
	{
		buff->sentence = ft_realloc(buff->sentence, BUFF_SIZE_P * buff->count);
		buff->count++;
	}
	while (spec->spc_conv[++index])
	{
		buff->sentence[buff->len] = spec->spc_conv[index];
		buff->len++;
	}
}

void		ft_putinbuff(t_buff *buff, char *format, int indx_format)
{
	if (buff->len == 0)
		buff->sentence = ft_strnew(BUFF_SIZE_P);
	if (buff->len == BUFF_SIZE_P * buff->count)
	{
		buff->sentence = ft_realloc(buff->sentence, BUFF_SIZE_P * buff->count);
		buff->count++;
	}
	buff->sentence[buff->len] = format[indx_format];
	buff->len++;
}
