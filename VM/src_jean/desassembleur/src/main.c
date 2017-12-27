/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:10:45 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/27 14:41:31 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crack.h"

int		main(int argc, char **argv)
{
	char	*new_file;

	new_file = NULL;
	if (argc != 2)
		error("Usage : ./crack <file.cor>");
	if (!parse_file(&new_file, argv[1]))
		return (0);
	ft_printf("Writing output program to %s\n", new_file);
	ft_strdel(&new_file);
	return (0);
}
