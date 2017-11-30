/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:54:28 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/30 19:44:44 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		realloc_order(t_order ****order, int *size)
{
	*size += 1;
	if ((*order = realloc(*order, sizeof(t_order *) \
					* (*size * SIZE_STRUCT))) == NULL)
		error("[ERR] : Ft. Realloc Failed\n");
}

static char		skip_blanks(char **s)
{
	if (!(s && *s && **s))
		return (-1);
	while ((**s) && ((**s) == SPACE || (**s) == TAB))
		(*s)++;
	return (0);
}

static _Bool	empty_line(t_file *file, char *s)
{
	if ((skip_blanks(&s) == -1) || ((*s == COMMENT_CHAR)\
				|| !(s)))
	{
		ft_strdel(&file->line);
		return (1);
	}
	return (0);
}

_Bool			instr_line(t_order ****tab, t_file *file, char *s)
{
	static int	check = 1;
	static int	size = 1;

	if (file->nb_line == (SIZE_STRUCT * size))
		realloc_order(tab, &size);
//	ft_printf("check : %d -- nb_line : %d\n", check, file->nb_line);
//	if (check != file->nb_line)
	if (!(**tab)[file->nb_line])
	{
		ft_putstr("test\n");
		(**tab)[file->nb_line] = ft_memalloc(sizeof(t_order));
		(**tab)[file->nb_line]->nb_label = 0;
		check++;
	}
//	if ((**tab)[file->nb_line]->nb_label > 0)
//		ft_printf("=== %s ===\n", (**tab)[file->nb_line]->label[0]);
	if (!pars_order((**tab)[file->nb_line], s))
		return (0);
	file->nb_line += (**tab)[file->nb_line]->op_code ? 1 : 0;
	return (1);
}

_Bool			launch_parsing(char *filepath, t_order ***tab, t_header *hdr)
{
	t_file		file;
	char		*tmp;

	if (!(tab && *tab) || **tab)
		error("[ERR] : corrupted slot to record instructions");
	if (!filepath || ((file.fd = open(filepath, O_RDONLY | O_SYMLINK)) < 0))
		error("[ERR] : opening failed on filepath");
	file.nb_line = 0;
	while ((file.ret = get_next_line(file.fd, &file.line)) == 1)
	{
		tmp = file.line;
		if (empty_line(&file, tmp))
		{
			ft_strdel(&file.line);
			continue ;
		}
		if (*tmp == DOT)
		{
			if (!pars_info(hdr, tmp))
			{
				ft_strdel(&file.line);
				return (0);
			}
		}
		else
		{
			if (!instr_line(&tab, &file, tmp))
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
