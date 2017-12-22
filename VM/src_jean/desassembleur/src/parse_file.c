/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:31:39 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/22 11:36:19 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crack.h"

static char		*new_name(char *old_file)
{
	char	*new_file;
	char	*ptr;
	char	*tmp;

	ptr = ft_strrchr(old_file, '.');
	tmp = ft_strsub(old_file, 0, ft_strlen(old_file) - ft_strlen(ptr));
	new_file = ft_strjoin(tmp, ".s");
	ft_strdel(&tmp);
	return (new_file);
}

static _Bool	check_file_name(char *file)
{
	char	*ptr;

	ptr = ft_strrchr(file, '.');
	if (ft_strlen(ptr) != 4 && ptr[1] != 'c' && ptr[2] != 'o' && ptr[3] != 'r')
	{
		ft_printf("Error : Bad extension for <%s>\n", file);
		ft_printf("Right extension : <file.cor>\n");
		return (0);
	}
	return (1);
}

static _Bool	close_files(char *old, char *new, int *fd_old, int *fd_new)
{
	if (close(*fd_old) == -1)
	{
		ft_printf("Can't close source file <%s>\n", *old);
		return (0);
	}
	if (close(*fd_new) == -1)
	{
		ft_printf("Can't close source file <%s>\n", *new);
		return (0);
	}
	return (1);
}

static _Bool	creat_new_file(char *old, char **new, int *fd_new)
{
	*new = new_name(old);
	if ((*fd_new = open(*new, O_CREAT | O_RDWR, 00770)) == -1)
	{
		ft_printf("Can't craet source file <%s>\n", new);
		return (0);
	}
	return (1);
}

_Bool			parse_file(char **new_file, char *old_file)
{
	int		fd_new;
	int		fd_old;

	if ((fd_old = open(old_file, O_RDONLY)) == -1)
	{
		ft_printf("Can't read source file <%s>\n", old_file);
		return (0);
	}
	if (!check_file_name(old_file))
		return (0);
	if (!parse_header(old_file, fd_old))
		return (0);
	if (!creat_new_file(old_file, new_file, &fd_new))
		return (0);
	write_header(fd_new, fd_old);
	write_instr(fd_new, fd_old);
	if (!close_files(old_file, *new_file, &fd_old, &fd_new))
		return (0);
	return (1);
}
