/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:17:18 by jpallard          #+#    #+#             */
/*   Updated: 2017/12/05 17:59:43 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		main(int argc, char **argv)
{
	int		i;
	int		*tab;

	i = 0;
	if (argc > 5)
		errorVM(); //to do;
	if (argc == 1)
		usage(); //to do;
	while (argv[i] < argc)
	{
		tab[i] = open(argv[i], O_RDONLY)
		if (tab[i] == - 1)
		errorVM();
