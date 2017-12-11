/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkheader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:00:13 by jpallard          #+#    #+#             */
/*   Updated: 2017/12/11 17:44:06 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/jordan.h"

void		littleendian(unsigned int *i)
{
	if (i != 0)
	{
		*i = ((*i >> 24) & 0xff)
		| ((*i << 8) & 0xff0000)
		| ((*i >> 8) & 0xff00)
		| ((*i << 24) & 0xff000000);
	}
}


void	init_proc(t_proc ***p, int fd)
{
	(**p) = ft_memalloc(sizeof(t_proc));
	(**p)->children = NULL;
	(**p)->carry = 0;
	(**p)->pc = 0;
	(**p)->name = NULL;
	get_next_line(fd, &(**p)->name);
}

/*
**check if each champ have the correct header attached to them and if the size 
**is correct
*/

void	checkheader(int fd, t_proc **p)
{
	unsigned int	i[1];
	unsigned int	j;

	read(fd, i, 4);
	littleendian(&i[0]);
	if (*i != COREWAR_EXEC_MAGIC)
		error_vm("invalid header");
	init_proc(&p, fd);
	lseek(fd, PROG_NAME_LENGTH + 8, SEEK_SET);
	read(fd, i, 4);
	littleendian(&i[0]);
	if (*i > CHAMP_MAX_SIZE)
		error_vm ("champ too big");
	else if (*i <= 0)
		error_vm("champ size is 0 or negative ?");
	j = lseek(fd, 0, SEEK_END);
	if (*i + PROG_NAME_LENGTH + COMMENT_LENGTH + (sizeof(int) * 4) != j)
		error_vm ("diff between file size and header prog_size");
}

