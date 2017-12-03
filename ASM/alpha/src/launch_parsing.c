/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:54:28 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/01 18:03:33 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static _Bool	instr_line(t_order ***tab, t_file *file, char *s)
{
	static int	size = 1;

	if (file->nb_line == (SIZE_STRUCT * size))
		realloc_order(tab, &size);
	if (!(*tab)[file->nb_line] || (file->nb_line >= SIZE_STRUCT))
	{
		(*tab)[file->nb_line] = ft_memalloc(sizeof(t_order));
		(*tab)[file->nb_line]->nb_label = 0;
	}
	if (!pars_order((*tab)[file->nb_line], s))
		return (0);
	file->nb_line += (*tab)[file->nb_line]->op_code ? 1 : 0;
	return (1);
}

_Bool			launch_parsing(char *filepath, t_order ***tab, t_header *hdr)
{
	t_file		file;
	char		*tmp;

	file.nb_line = 0;
	if (!filepath || ((file.fd = open(filepath, O_RDONLY /*| O_SYMLINK*/)) < 0))
		error("[ERR] : opening failed on filepath");
	while ((file.ret = get_next_line(file.fd, &file.line)) == 1)
	{
		tmp = file.line;
		if (empty_line(&file, tmp))
			continue ;
		if (breaking_line(tmp))
			break ;
		if (*tmp == DOT)
		{
			if (!pars_info(hdr, tmp))
			{			ft_printf("%c\n", *tmp);

				ft_strdel(&file.line);
				return (0);
			}
		}
		else
		{
			if (!(hdr->if_prog || hdr->if_comment))
				error("[ERR] : Header");
			if (!instr_line(tab, &file, tmp))
			{
				ft_strdel(&file.line);
				return (0);
			}
		}
		ft_strdel(&file.line);
	}
	hdr->nb_struct = file.nb_line;
	write_order_pos(*tab, hdr->nb_struct);
	if (close(file.fd) != 0)
		error("[ERR] : parsing file closing failed");
	return (1);
}
