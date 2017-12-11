/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:17:18 by jpallard          #+#    #+#             */
/*   Updated: 2017/12/11 18:12:54 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/jordan.h"

/*
** MAIN,  MODIFY WITH CAUTION
*/

int		main(int argc, char **argv)
{
	int				i;
	int				*tab;
	unsigned char	*arene;
	t_proc			**p;

	i = 1;
	arene = NULL;
	if (argc > 5)
		error_vm("too many champion");
	if (argc == 1)
		error_vm("usage to do list");
	tab = ft_memalloc(sizeof(int) * 4);
	p = ft_memalloc(sizeof(t_proc) * argc - 1);
	while (i < argc)
	{
		tab[i - 1] = open(argv[i], O_RDONLY);
		if (tab[i - 1] == -1)
			error_vm("Open FAILED wtf");
		checkheader(tab[i - 1], &p[i - 1]);

		i++;
	}
	arene = load_champ(tab, argc - 1, p);
	ft_printf("p[0] = %s, %u\n p[1] = %s, %u\n", p[0]->name, p[0]->pc, p[1]->name, p[1]->pc);
	//free(arene);
	//free(tab);
	return (0);
}
