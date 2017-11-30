/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:54:28 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/30 15:50:27 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	realloc_order(t_order ***order, int *size)
{
	*size += 1;
	if ((*order = realloc(*order, sizeof(t_order *) \
					* (*size * SIZE_STRUCT))) == NULL)
		error("[ERR] : Ft. Realloc Failed\n");
}

static char	skip_blanks(char **s)
{
	if (!(s && *s && **s))
		return (-1);
	while ((**s) == SPACE || (**s) == TAB)
		(*s)++;
	return (0);
}

_Bool	launch_parsing(char *filepath, t_order ***tab, t_header *hdr)
{
	t_file		file;
	char		*to_free;
	int			size;
	int			index;

	if (!(tab && *tab) || **tab)
		error("[ERR] : corrupted slot to record instructions");
	if (!filepath || ((file.fd = open(filepath, O_RDONLY | O_SYMLINK)) < 0))
		error("[ERR] : opening failed on filepath");
	size = 1;
	file.nb_line = 0;
	while ((file.ret = get_next_line(file.fd, &file.line)) == 1)
	{
		to_free = file.line;
		if ((skip_blanks(&file.line) == -1) || ((*file.line == COMMENT_CHAR)\
					|| !(*file.line)))
		{
			if (to_free)
				ft_strdel(&to_free);
			continue ;
		}
		if (*file.line == DOT)
		{
			if (!pars_info(hdr, file.line))
			{
				ft_strdel(&to_free);
				return (0);
			}
			ft_printf(".name = [%s], .comment = [%s]\n", hdr->prog_name, hdr->comment);
		}
		else
		{
			if (file.nb_line == (SIZE_STRUCT * size))
				realloc_order(tab, &size);
			if (((*tab)[file.nb_line] = ft_memalloc(sizeof(t_order))) == NULL)
				exit(0);
			if (!pars_order((*tab)[file.nb_line], file))//exit if returns 0?
			{
				ft_strdel(&to_free);
				return (0);
			}
			index = -1;
			while (++index < (*tab)[file.nb_line]->nb_param)
				ft_printf("param[%d]: %s, ty_param[%d]: %d\n", index, \
						(*tab)[file.nb_line]->param[index], index,\
						(*tab)[file.nb_line]->ty_param[index]);
			file.nb_line += (*tab)[file.nb_line]->op_code ? 1 : 0;
		}
		ft_strdel(&to_free);
	}
	hdr->nb_struct = file.nb_line;
	write_order_pos(*tab, hdr->nb_struct);
	if (close(file.fd) != 0)
		error("[ERR] : parsing file closing failed");
	return (1);
}
