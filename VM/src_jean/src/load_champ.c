/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:57:33 by jpallard          #+#    #+#             */
/*   Updated: 2017/12/20 11:19:32 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**function wich load each champ with MEM_SIZE/number of champ octet between them
**on MEM_SIZE (unsigned char) octet.
*/

unsigned char	*load_champ(int *tab, short nb, t_proc **p, t_win **w)
{
	int				i;
	unsigned char	*mem;
	unsigned int	size[1];
	unsigned int	space;

	i = 0;
	space = 0;
	mem = ft_memalloc(sizeof(unsigned char) * MEM_SIZE);
	if (g_print == 1 && nb != -1)
	{
		*w = ft_memalloc(sizeof(t_win));
		start_ncurses(*w, p);
	}
	while (i < nb)
	{
		lseek(tab[i], PROG_NAME_LENGTH + 8, SEEK_SET);
		read(tab[i], size, 4);
		littleendian(&size[0]);
		lseek(tab[i], COMMENT_LENGTH + 4, SEEK_CUR);
		read(tab[i], mem + space, size[0]);
		p[i]->pc = space;
		if (close(tab[i]) == -1)
			error_vm("Error : close");
		space = MEM_SIZE/nb + space;
		if (g_print == 1 && nb != -1)
		{
			(*w)->start = MEM_SIZE/nb - space;
			(*w)->start *= -1;
			if ((*w)->start != 0)
				(*w)->start -= 64;
			(*w)->end = space;
			draw_arena(*w, mem, p[i]->color);
		}
		i++;
	}
	return (mem);
}
