/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:57:33 by jpallard          #+#    #+#             */
/*   Updated: 2018/02/08 17:26:44 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	function which loads each champ with MEM_SIZE/number of champ octet between
**	them on MEM_SIZE (unsigned char) octet.
*/

static void		init_curses(t_info *info, t_proc **p, unsigned char *mem)
{
	if (!info->opt[0])
		return ;
	start_ncurses(info, p);
	init_arena(info, mem);
}

static void		launch_curses(unsigned int space, t_proc *buf, int size,\
		unsigned char *mem)
{
	t_info	*info;

	info = get_info(NULL);
	if (!info->opt[0])
		return ;
	info->start = MEM_SIZE / info->nb_player - space;
	info->start *= -1;
	info->end = info->start + size;
	refresh_arena(info, mem, buf->color);
}

unsigned char	*load_champ(int *tab, t_proc **p, t_info *info)
{
	int				i;
	unsigned char	*mem;
	unsigned int	size[1];
	unsigned int	space;
	t_proc			*buf;

	i = 0;
	space = 0;
	mem = ft_memalloc(sizeof(unsigned char) * MEM_SIZE);
	init_curses(info, p, mem);
	while ((buf = proc_unqueue()) && (i < info->nb_player))
	{
		lseek(tab[i], PROG_NAME_LENGTH + 8, SEEK_SET);
		read(tab[i], size, 4);
		littleendian(&size[0]);
		lseek(tab[i], COMMENT_LENGTH + 4, SEEK_CUR);
		read(tab[i], mem + space, size[0]);
		buf->pc = space;
		if (close(tab[i]) == -1)
			error_vm("Error : close");
		space = MEM_SIZE / info->nb_player + space;
		launch_curses(space, buf, *size, mem);
		i++;
	}
	return (mem);
}
