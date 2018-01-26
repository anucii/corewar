/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 11:54:03 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/30 12:27:11 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		check_int(char *nb)
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
