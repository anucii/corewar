/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 14:57:52 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/30 11:32:59 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

//	-c curses
//	-n players [1param]
//	-dump [1param]
//	-v verbos [1param]

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

static void		check_int(char *nb)
{
	int		index;
	int		len;

	index = 0;
	len = 0;
	while (nb[index] == '-' || nb[index] == '+')
		index++;
	if (index > 1)
		print_usage("Error : format of -dump error");
	if ((len = ft_strlen(nb) - index) < 0)
		len *= -1;
	if (len > 11 || ft_atoi(nb) < -2147483647 || ft_atoi(nb) > 2147483647)
		print_usage("Error : Int Needed for opt -dump and -v");
	while (ft_isdigit(nb[index]))
		index++;
	if (nb[index] != '\0')
		print_usage("Error : Int Needed for opt -dump and -v");
}

static _Bool	check_opt(t_info *info, char **arg, int *index)
{
	if (ft_strequ(arg[*index], "-c"))
	{
		if (info->opt[0])
			error_vm(""RED"Error : Option -c already given"RESET"");
		info->opt[0] = 1;
		return (1);
	}
	if (ft_strequ(arg[*index], "-dump"))
	{
		if (info->opt[1])
			error_vm(""RED"Error : Option -dump already given"RESET"");
		if (!arg[(*index) + 1])
			print_usage("Error : format of -dump error");
		check_int(arg[(*index) + 1]);
		info->opt[1] = 1;
		if ((info->opt[2] = ft_atoi(arg[(*index) + 1])) < 0)
			print_usage("Error : Positive int Needed for opt -dump and -v");
		*index += 1;
		return (1);
	}
	if (ft_strequ(arg[*index], "-dump"))
	{
		if (info->opt[3])
			error_vm(""RED"Error : Option -v already given"RESET"");
	}
	return (0);
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
		print_usage("");
	while (++index[0] < argc)
	{
		if (check_opt(info, argv, &index[0]))
			continue ;
		else
		{
			if (++index[1] == 0)
				tab = ft_memalloc(sizeof(int));
			else if (index[1] >= MAX_PLAYERS)
				print_usage("Too many players\n");
			else if ((tab = (int*)realloc(tab, sizeof(int) * index[1] + 1)) == NULL)
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
