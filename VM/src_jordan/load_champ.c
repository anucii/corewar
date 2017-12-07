/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:57:33 by jpallard          #+#    #+#             */
/*   Updated: 2017/12/07 18:02:13 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/jordan.h"

/*
**function wich load each champ with MEM_SIZE/nb octet between them
**on MEM_SIZE octet
*/

char	*load_champ(int *tab, short nb)
{
	int				i;
	char			*mem;
	unsigned int	size[1];
	int				fd;
	int				space;

	i = 0;
	space = 0;
	mem = ft_strnew(MEM_SIZE + 1);
	while (i < nb)
	{
		lseek(tab[i], PROG_NAME_LENGTH + 8, SEEK_SET);
		read(tab[i], size, 4);
		littleendian(&size[0]);
		lseek(tab[i], COMMENT_LENGTH + 4, SEEK_CUR);
		read(tab[i], mem + space, size[0]);
		if (close(tab[i]) == -1)
			error_vm("err : close");
		i++;
		space = MEM_SIZE/nb + space;
	}
	// part used for debugging acual bug = abort when nb = 4 will investiget later
	fd = open("test.MEM", O_CREAT | O_RDWR, 00770);
	write(fd, mem, MEM_SIZE);
	close(fd);
	ft_printf("succes !\n");
	return(mem);
}
