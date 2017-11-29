#ifndef GNL_H
# define GNL_H

#include "libft.h"

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
