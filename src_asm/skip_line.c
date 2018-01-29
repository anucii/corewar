/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:53:35 by jdaufin           #+#    #+#             */
/*   Updated: 2018/01/26 15:48:39 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	skip_blanks(char **s)
{
	if (!(s && *s && **s))
		return (-1);
	while ((**s) && ((**s) == SPACE || (**s) == TAB))
		(*s)++;
	return (**s ? 0 : -1);
}

_Bool	empty_line(t_file *file, char *s)
{
	if ((skip_blanks(&s) == -1) || ((*s == COMMENT_CHAR)\
				|| !(s)))
	{
		file->empty += 1;
		ft_strdel(&file->line);
		return (1);
	}
	return (0);
}

_Bool	breaking_line(char *s)
{
	while (*s && ft_isdigit(*s))
		(s)++;
	skip_blanks(&s);
	if (!(*s))
		return (1);
	return (0);
}
