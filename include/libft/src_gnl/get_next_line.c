/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 13:37:56 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/05 14:45:39 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_search		*ft_new(int fd, t_search *file)
{
	file = ft_memalloc(sizeof(t_search));
	file->fd = fd;
	file->save = ft_memalloc(sizeof(file->save) * BUFF_SIZE_G);
	file->prev = NULL;
	file->next = NULL;
	return (file);
}

static t_search		*ft_check_fd(int fd, t_search *file)
{
	t_search		*tmp;

	if (!file)
		file = ft_new(fd, file);
	else
	{
		while (file->prev != NULL)
			file = file->prev;
		while (file->fd != fd)
		{
			if (file->next == NULL)
			{
				tmp = file;
				file->next = ft_new(fd, file);
				file = file->next;
				file->prev = tmp;
				return (file);
			}
			tmp = file;
			file = file->next;
			file->prev = tmp;
		}
	}
	return (file);
}

static int			ft_check_save(t_search *file, char **line)
{
	char		*tmp;

	tmp = NULL;
	if ((tmp = ft_strchr(file->save, '\n')))
	{
		ft_strdup(tmp);
		file->save[ft_strlen(file->save) - ft_strlen(tmp)] = '\0';
		*line = ft_strdup(file->save);
		ft_strdel(&file->save);
		file->save = ft_strsub(tmp, 1, BUFF_SIZE_G);
		return (1);
	}
	return (0);
}

static int			ft_get_line(char *buf, char **line, t_search *file, int ret)
{
	char		*tmp;

	tmp = NULL;
	buf[ret] = '\0';
	if ((tmp = ft_strchr(buf, '\n')))
	{
		tmp = ft_strdup(tmp);
		buf[ft_strlen(buf) - ft_strlen(tmp)] = '\0';
		*line = ft_strjoin(file->save, buf);
		ft_strdel(&file->save);
		file->save = ft_strsub(tmp, 1, BUFF_SIZE_G);
		ft_strdel(&tmp);
		ft_strdel(&buf);
		return (1);
	}
	tmp = ft_strdup(file->save);
	ft_strdel(&file->save);
	file->save = ft_strjoin(tmp, buf);
	ft_strdel(&tmp);
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static t_search	*file;
	char			*buf;
	int				ret;

	file = ft_check_fd(fd, file);
	buf = ft_memalloc(BUFF_SIZE_G);
	if (file->save)
		if (ft_check_save(file, &*line))
			return (1);
	while ((ret = read(fd, buf, BUFF_SIZE_G)) == 1)
	{
		if (ret == -1)
			return (-1);
		if (ft_get_line(buf, &*line, file, ret))
			return (1);
	}
	ft_strdel(&buf);
	if (ft_strlen(file->save) != '\0')
	{
		*line = ft_strdup(file->save);
		ft_strdel(&file->save);
		file->save = ft_strnew(0);
		return (1);
	}
	return (0);
}
