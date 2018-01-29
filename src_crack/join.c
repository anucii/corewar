/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:31:28 by jgonthie          #+#    #+#             */
/*   Updated: 2018/01/04 14:37:44 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crack.h"

char	*new_join(char *s, char *to_join)
{
	char	*tmp;
	char	*new;

	tmp = ft_strdup(s);
	ft_strdel(&s);
	new = ft_strjoin(to_join, tmp);
	ft_strdel(&tmp);
	return (new);
}
