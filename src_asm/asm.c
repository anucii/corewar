/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:22:52 by jgonthie          #+#    #+#             */
/*   Updated: 2018/02/27 17:48:05 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int argc, char **argv)
{
	t_order		**tab;
	t_header	hdr;
	t_file		file;

	tab = ft_memalloc(sizeof(t_order**) * (SIZE_STRUCT));
	if (argc < 2)
		error("Usage : ./parser <line content space-separated>");
	init_hdr(&hdr, argv[argc - 1]);
	file.nb_line = 0;
	file.empty = 0;
	file.size = 1;
	if (!launch_parsing(argv[argc - 1], &tab, &hdr, &file))
		error_parsing(file.nb_line + file.empty);
	write_order_pos(tab, &file, hdr.nb_struct);
	calc_prog_size(tab, &hdr);
	writeinst(tab, &hdr);
	ft_printf("Writing output program to %s\n", hdr.filename);
	ft_strdel(&file.line);
	ft_strdel(&hdr.filename);
	free_order(tab, hdr.nb_struct);
	return (0);
}
