/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 14:57:52 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/30 12:46:57 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		prepare_pars(t_proc ****p, int *tab, t_info *info, int index)
{
	if (tab[index] == -1)
	{
		ft_printf("Error : Open failed on file [%s]", info->name);
		error_vm("");
	}
	else if (index > 0)
	{
		(**p) = (t_proc**)realloc((**p), sizeof(t_proc) * index + 1);
		if ((**p) == NULL)
			error_vm("Ft. Realloc() failed");
	}
	parse_header(tab[index], &(**p)[index], info);
}

static _Bool	check_opt(t_info *info, char **arg, int *index, int id)
{
	if (ft_strequ(arg[*index], "-c"))
	{
		check_curse(info);
		return (1);
	}
	if (ft_strequ(arg[*index], "-dump"))
	{
		check_dump(info, arg, index);
		return (1);
	}
	if (ft_strequ(arg[*index], "-v"))
	{
		check_verbos(info, arg, index);
		return (1);
	}
	if (ft_strequ(arg[*index], "-n"))
	{
		check_id_player(info, arg, index, id);
		return (1);
	}
	return (0);
}

/*
**	Deux index :	- index[0] incremente pour chaque ARG
**					- index[1] incremente que l'ARG n'est pas une option et
**						sert aussi d'index pour le tableau (int *tab) de FD
*/

t_info			*check_arg(t_proc ***p, unsigned char **arena,\
		char **argv, int argc)
{
	t_info		*info;
	int			*tab;
	int			index[2];

	index[0] = 0;
	index[1] = -1;
	info = ini_info();
	if (argc == 1)
		print_usage("");
	while (++index[0] < argc)
	{
		if (check_opt(info, argv, &index[0], index[1]))
			continue ;
		else
		{
			if (++index[1] == 0)
				tab = ft_memalloc(sizeof(int));
			else if (index[1] >= MAX_PLAYERS)
				print_usage("Too many players");
			else if ((tab = (int*)realloc(tab, sizeof(int) * index[1] + 1))
					== NULL)
				error_vm("Error : Ft. realloc failed");
			tab[index[1]] = open(argv[index[0]], O_RDONLY);
			strcpystatic(&info->name[index[1]], argv[index[0]]);
			prepare_pars(&p, tab, info, index[1]);
		}
	}
	if (index[1] == -1)
		print_usage("");
	info->nb_player = index[1] + 1;
	*arena = load_champ(tab, *p, info);
	ft_memdel((void**)&tab);
	return (info);
}
