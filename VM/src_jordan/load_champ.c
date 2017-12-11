/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:57:33 by jpallard          #+#    #+#             */
/*   Updated: 2017/12/11 18:10:05 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/jordan.h"

/*
**function wich load each champ with MEM_SIZE/number of champ octet between them
**on MEM_SIZE (unsigned char) octet.
*/

unsigned char	*load_champ(int *tab, short nb, t_proc **p)
{
	int				i;
	unsigned char	*mem;
	unsigned int	size[1];
//	int				fd;
	unsigned int	space;

	i = 0;
	space = 0;
	mem = ft_memalloc(sizeof(unsigned char) * MEM_SIZE);
	while (i < nb)
	{
		lseek(tab[i], PROG_NAME_LENGTH + 8, SEEK_SET);
		read(tab[i], size, 4);
		littleendian(&size[0]);
		lseek(tab[i], COMMENT_LENGTH + 4, SEEK_CUR);
		read(tab[i], mem + space, size[0]);
		p[i]->pc = space;
		if (close(tab[i]) == -1)
			error_vm("err : close");
		i++;
		space = MEM_SIZE/nb + space;
	}
	/* part used for debugging 
	fd = open("test.MEM", O_CREAT | O_RDWR, 00770);
	write(fd, mem, MEM_SIZE);
	close(fd);*/
	return(mem);
}
