/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:17:18 by jpallard          #+#    #+#             */
/*   Updated: 2017/12/14 14:16:53 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/jordan.h"

/*
**	MAIN,  MODIFY WITH CAUTION
**	Warning : this function assumes that all arguments are program files
**	which is not the case if options arguments are implemented, and which does
**	not protect the VM against wrong user input.
*/

unsigned int	g_n_players = 0;

int				main(int argc, char **argv)
{
	int				i;
	int				*tab;
	unsigned char	*arene;
	t_proc			**p;

	i = 1;
	arene = NULL;
	if (argc > 5)
		error_vm("Too many champions");
	if (argc == 1)
		error_vm("usage to do list");
	g_n_players = argc - 1; //adapt to the handling of options plus the fake files
	tab = ft_memalloc(sizeof(int) * 4);
	p = ft_memalloc(sizeof(t_proc) * argc - 1);
	while (i < argc)
	{
		tab[i - 1] = open(argv[i], O_RDONLY);
		if (tab[i - 1] == -1)
			error_vm("Open FAILED wtf");
		checkheader(tab[i - 1], &p[i - 1], new_player());

		i++;
	}
	arene = load_champ(tab, argc - 1, p);
	ft_printf("p[0] = %s, %u\n p[1] = %s, %u\n", p[0]->name, p[0]->pc, p[1]->name, p[1]->pc);
	run(arene, p);

	//free(arene);
	//free(tab);
	return (0);
}
