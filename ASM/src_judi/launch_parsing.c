/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:54:28 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/28 22:05:13 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "judi.h"

static char	skip_blanks(char **s)
{
	if (!(s && *s && **s))
		return (-1);
	while (*s && ft_isspace(**s))
		(*s)++;
	return (0);
}

void	launch_parsing(char *filepath, t_order **tab, t_header *hdr)
{
	int			size;
	t_file		file;

	if (!tab || *tab)
		ft_error("[ERR] : corrupted slot to record instructions");
	if (!filepath || ((file.fd = open(filepath, O_RDONLY | O_SYMLINK)) < 0))
		ft_error("[ERR] : opening failed on filepath");
	size = 1;
	file.nb_line = 0;
	*tab = (t_order *)ft_memalloc(sizeof(t_order) * SIZE_STRUCT * size);
	while ((file.ret = get_next_line(file.fd, &file.line)) == 1)
	{
		if ((skip_blanks(&file.line) == -1) || ((*file.line == COMMENT_CHAR)\
					|| !(*file.line)))
			continue ;
		if (*file.line == DOT)
			ft_pars_info(hdr, file.line);
		else
		{
			if (file.nb_line == (SIZE_STRUC * size))
				ft_realloc_order(tab, &size);
			ft_pars_order(tab[file.nb_line], file);//exit if returns 0?
			file.nb_line += tab[file.nb_line].op_code ? 1 : 0; 
		}
	}
}
