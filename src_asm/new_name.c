/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:23:03 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/04 16:48:28 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*new_name(t_header *file)
{
	char	*file_name;
	char	*tmp;

	tmp = ft_strrchr(file->filename, DOT);
	file_name = ft_strsub(file->filename, 0,\
			ft_strlen(file->filename) - ft_strlen(tmp));
	tmp = ft_strjoin(file_name, ".cor");
	ft_strdel(&file_name);
	file_name = ft_strdup(tmp);
	ft_strdel(&tmp);
	ft_strdel(&file->filename);
	return (file_name);
}
