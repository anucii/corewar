/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:54:28 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/04 16:47:50 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static _Bool	parse_header(t_file *file, t_header *hdr, char *s)
{
	if (!pars_info(hdr, s))
	{
		ft_strdel(&file->line);
		return (0);
	}
	return (1);
}

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

static _Bool	check_inst(t_order ***tab, t_file *file, t_header *hdr, char *s)
{
	if (!(hdr->if_prog || hdr->if_comment))
		error("[ERR] : Header");
	if (!instr_line(tab, file, s))
	{
		ft_strdel(&file->line);
		return (0);
	}
	return (1);
}

_Bool			launch_parsing(char *filepath, t_order ***tab, t_header *hdr, \
						t_file *fle)
{
	char		*tmp;

	if (!filepath || ((fle->fd = open(filepath, O_RDONLY | O_SYMLINK)) < 0))
		error("[ERR] : opening failed on filepath");
	while ((fle->ret = get_next_line(fle->fd, &fle->line)) == 1)
	{
		tmp = fle->line;
		if (empty_line(fle, tmp))
			continue ;
		if (breaking_line(tmp))
			break ;
		if (*tmp == DOT)
		{
			if (!parse_header(fle, hdr, tmp))
				return (0);
		}
		else if (!check_inst(tab, fle, hdr, tmp))
			return (0);
		ft_strdel(&fle->line);
	}
	hdr->nb_struct = fle->nb_line;
	if (close(fle->fd) != 0)
		error("[ERR] : parsing file closing failed");
	return (1);
}
