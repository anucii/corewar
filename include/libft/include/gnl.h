/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:43:29 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/05 14:44:02 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include "libft.h"

# define BUFF_SIZE_G 1

typedef struct		s_search
{
	int				fd;
	char			*save;
	struct s_search	*prev;
	struct s_search	*next;
}					t_search;

int					get_next_line(const int fd, char **line);

#endif
