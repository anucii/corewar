/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 14:57:52 by jgonthie          #+#    #+#             */
/*   Updated: 2018/02/28 10:35:02 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		prepare_pars(t_proc **p, int *tab, t_info *info, int index)
{
	if (tab[index] == -1)
	{
		ft_printf("Error : Open failed on file [%s]", info->name);
		error_vm("");
	}
	parse_header(tab[index], p, info);
}

static void		check_file(int **tab, int *index)
{
	if (++index[1] == 0)
		*tab = ft_memalloc(sizeof(int));
	else if (index[1] >= MAX_PLAYERS)
		print_usage("Too many players");
	else if ((*tab = (int*)realloc(*tab, sizeof(int) * (index[1] + 1)))
			== NULL)
		error_vm("Error : Ft. realloc failed");
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

t_info			*check_arg(t_proc **p, unsigned char **arena,\
		char **argv, int argc)
{
	t_info		*info;
	int			*tab;
	int			index[2];

	info = ini_info(&index);
	if (argc == 1)
		print_usage("");
	while (++index[0] < argc)
	{
		if (check_opt(info, argv, &index[0], index[1]))
			continue ;
		else
		{
			check_file(&tab, index);
			tab[index[1]] = open(argv[index[0]], O_RDONLY);
			strcpystatic(&info->name[index[1]], argv[index[0]]);
			prepare_pars(p, tab, info, index[1]);
		}
	}
	if (index[1] == -1)
		print_usage("");
	info_player(info, index[1] + 1);
	*arena = load_champ(tab, p, get_info(&info));
	ft_memdel((void**)&tab);
	return (info);
}
