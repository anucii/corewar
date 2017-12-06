/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:17:18 by jpallard          #+#    #+#             */
/*   Updated: 2017/12/06 17:07:30 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/jordan.h"

int		main(int argc, char **argv)
{
	int		i;
	int		tab[4] = {0};

	i = 1;
	if (argc > 5)
		error_vm("too many champion");
	if (argc == 1)
		error_vm("usage to do list");
	while (i < argc)
	{
		tab[i] = open(argv[i], O_RDONLY);
		if (tab[i] == -1)
			error_vm("Open FAILED wtf");
		checkheader(tab[i]);
		close(tab[i]);
		i++;
	}
}
