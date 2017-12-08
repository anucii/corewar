/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:17:18 by jpallard          #+#    #+#             */
/*   Updated: 2017/12/08 17:39:20 by jpallard         ###   ########.fr       */
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

	i = 1;
	arene = NULL;
	if (argc > 5)
		error_vm("too many champion");
	if (argc == 1)
		error_vm("usage to do list");
	tab = ft_memalloc(sizeof(int) * 4);
	while (i < argc)
	{
		tab[i - 1] = open(argv[i], O_RDONLY);
		if (tab[i - 1] == -1)
			error_vm("Open FAILED wtf");
		checkheader(tab[i - 1]);
		i++;
	}
	arene = load_champ(tab, argc - 1);
	//free(arene);
	//free(tab);
	return (0);
}
