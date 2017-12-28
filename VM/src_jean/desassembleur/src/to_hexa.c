/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 18:18:11 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/28 18:24:35 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crack.h"

char	*to_hexa(unsigned char c1, unsigned char c2)
{
	char	*join;
	char	*o1;
	char	*o2;

	o1 = ft_strbase(c1, "0123456789abcdef");
	o2 = ft_strbase(c2, "0123456789abcdef");
	join = ft_strjoin(o1, o2);
	ft_strdel(&o1);
	ft_strdel(&o2);
	return (join);
}
