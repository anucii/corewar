/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:03:39 by jgonthie          #+#    #+#             */
/*   Updated: 2017/07/20 13:32:53 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putandfree(t_buff *buff)
{
	if (buff->len != -1)
		write(1, buff->sentence, buff->len);
	ft_strdel(&buff->sentence);
	if (buff->check == 1)
		buff->len = -1;
}

int				ft_printf(const char *restrict format, ...)
{
	va_list			ap;
	static t_buff	buff;
	t_spec			spec;
	int				index;

	index = -1;
	ft_inistruct(&buff, &spec);
	va_start(ap, format);
	while (format[++index])
	{
		if (format[index] == '%')
		{
			index = ft_checkspec(&spec, (char*)format, index + 1);
			if (format[index] == '\0')
				break ;
			ft_spec(&buff, &spec, ap);
			if (buff.len == -1)
				break ;
		}
		else
			ft_putinbuff(&buff, (char*)format, index);
	}
	ft_putandfree(&buff);
	va_end(ap);
	return (buff.len);
}
