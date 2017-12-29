/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 14:57:52 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/29 19:53:47 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

//	-c curses
//	-n players [1param]
//	-dump [1param]
//	-v verbos [1param]

static t_info	*ini_info(void)
{
	t_info		*info;
	int 		index;

	index = -1;
	info = ft_memalloc(sizeof(t_info));
	while (++index)
		ft_memset(info->name[index], 0, 255);
	ft_memset(info->opt, 0, 5);
	info->nb_of_player[0] = -1;
	info->nb_of_player[1] = -2;
	info->nb_of_player[2] = -3;
	info->nb_of_player[3] = -4;
	info->nb_player = 0;
	info->win = NULL;
	info->start = 0;
	info->end = 0;
	return (info);
}

static void		inc_opt_print(t_info *info)
{
	if (info->opt[0] == 1)
		error_vm("Error : Option -c already given");
	info->opt[0] = 1;
}

static void		print_usage(void)
{
	ft_printf(""RED"Usage:"RESET"\n\
./corewar ["BLACK"-c"RESET"] ["GREEN"-n"RESET" number] ["PURPLE"-dump"RESET" \
number] ["CYAN"-v"RESET" number] <champ.cor> <...> \
[%d players max]\n"YELLOW"### OPTION ###"RESET"\n\
"BLACK"-c"RESET"	: nCurses output mode\n\
"GREEN"-n"RESET"	: number of player\n\
"PURPLE"-dump"RESET"	: dumps memory after N cycles then exits\n\
"CYAN"-v"RESET"	: verbos output mode", MAX_PLAYERS);
	error_vm("");
}

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

/*
**	Deux index :	- index[0] incremente pour chaque ARG
**					- index[1] incremente que l'ARG n'est pas une option et
**						sert aussi d'index pour le tableau (int *tab) de FD
*/

t_info			*check_arg(t_proc ***p, unsigned char **arena, char **argv, int argc)
{
	t_info		*info;
	int			*tab;
	int			index[2];
	int			size;

	size = 0;
	index[0] = 0;
	index[1] = -1;
	info = ini_info();
	if (argc == 1)
		print_usage();
	while (++index[0] < argc)
	{
		info->opt[0] =1;
		if (ft_strequ(argv[index[0]], "-c"))
			inc_opt_print(info);
		else
		{
			if (++index[1] == 0)
				tab = ft_memalloc(sizeof(int));
			else if (index[1] >= MAX_PLAYERS)
			{
				ft_printf("Too many players\n");
				print_usage();
			}
			else if ((tab = (int*)realloc(tab, sizeof(int) * index[1] + 1)) == NULL)
				error_vm("Error : Ft. realloc failed");
			tab[index[1]] = open(argv[index[0]], O_RDONLY);
			strcpystatic(&info->name[index[1]], argv[index[0]]);
			prepare_pars(&p, tab, info, index[1]);
		}
	}
	if (index[1] == -1)
		print_usage();
	info->nb_player = index[1] + 1;
	*arena = load_champ(tab, *p, info);
   	ft_memdel((void**)&tab);
	return (info);
}
