/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:10:45 by jgonthie          #+#    #+#             */
/*   Updated: 2018/02/28 10:33:49 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crack.h"

int		main(int argc, char **argv)
{
	char	*new_file;

	new_file = NULL;
	if (argc != 2)
	{
		ft_printf("Usage : ./crack <file.cor>\n");
		return (0);
	}
	if (!parse_file(&new_file, argv[1]))
		;
	else
		ft_printf("Writing output program to %s\n", new_file);
	ft_strdel(&new_file);
	return (0);
}
