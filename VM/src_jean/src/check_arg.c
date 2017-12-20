/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 14:57:52 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/20 11:08:00 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	inc_opt_print(void)
{
	if (g_print == 1)
		error_vm("Error : Option -n already given");
	g_print = 1;
}

static void	print_usage(void)
{
	ft_printf("Usage: ./corewar [-n] <champ.cor> <...> [%d players max]\n", MAX_PLAYERS);
	ft_printf("### NCURSES OUTPUT MODE ###\n");
	ft_printf("-n        : Ncurses output mode");
	error_vm("");
}

static void	prepare_pars(t_proc ****p, int *tab, char *name_file, int index)
{
	if (tab[index] == -1)
	{
		ft_printf("Error : Open failed on file [%s]", name_file);
		error_vm("");
	}
	if (index > 0)
		(**p) = (t_proc**)realloc((**p), sizeof(t_proc) * index + 1);
	parse_header(tab[index], &(**p)[index], name_file);
}

t_win		*check_arg(t_proc ***p, unsigned char **arena, char **argv, int argc)
{
	t_win	*w;
	int		*tab;
	int		size;
	int		i;
	int		y;

	size = 0;
	w = NULL;
	y = -1;
	i = 0;
	if (argc == 1)
		print_usage();
	while (++i < argc)
	{
		if (ft_strequ(argv[i], "-n"))
			inc_opt_print();
		else
		{
			if (++y == 0)
				tab = ft_memalloc(sizeof(int));
			else if (y >= MAX_PLAYERS)
			{
				ft_printf("Too many players\n");
				print_usage();
			}
			else if ((tab = (int*)realloc(tab, sizeof(int) * y + 1)) == NULL)
				error_vm("Error : Ft. realloc failed");
			tab[y] = open(argv[i], O_RDONLY);
			prepare_pars(&p, tab, argv[i], y);
		}
	}
	if (y == -1)
		print_usage();
	*arena = load_champ(tab, y + 1, *p, &w);
   	ft_memdel((void**)&tab);
	return (w);
}
