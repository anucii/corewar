/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:56:34 by jgonthie          #+#    #+#             */
/*   Updated: 2018/01/04 14:57:46 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crack.h"

_Bool	close_files(char *old, char *new, int *fd_old, int *fd_new)
{
	if (close(*fd_old) == -1)
	{
		ft_printf("Can't close source file <%s>\n", *old);
		return (0);
	}
	if (close(*fd_new) == -1)
	{
		ft_printf("Can't close source file <%s>\n", *new);
		return (0);
	}
	return (1);
}
