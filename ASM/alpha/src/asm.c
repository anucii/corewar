/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:22:52 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/01 18:08:01 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int     main(int argc, char **argv)
{
	t_order     **tab;
	t_header    hdr;
	t_file		file;

	tab = ft_memalloc(sizeof(t_order**) * (SIZE_STRUCT));
	if (argc < 2)
		error("Usage : ./parser <line content space-separated>");
	init_hdr(&hdr, argv[argc - 1]);
	file.nb_line = 0;
	if (!launch_parsing(argv[argc - 1], &tab, &hdr, &file))
		error("[ERR] : parsing failure");
	write_order_pos(tab, hdr.nb_struct);
	calc_prog_size(tab, &hdr);
	writeinst(tab, &hdr);
	ft_strdel(&hdr.filename);
	free_order(tab, hdr.nb_struct);
	ft_printf("Writing output program to %s\n", argv[argc - 1]);
	return (0);
}
