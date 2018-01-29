/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpystatic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 19:04:54 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/29 19:14:33 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		strcpystatic(char (*dest)[255], char *copy)
{
	int		index;

	index = -1;
	while (copy[++index])
		(*dest)[index] = copy[index];
}
