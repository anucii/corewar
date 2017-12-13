/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_vm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:52:38 by jpallard          #+#    #+#             */
/*   Updated: 2017/12/13 12:13:51 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/jordan.h"

/*
**YOU REALLY NEED A COMMENT FOR THIS ONE !?
**YES PLEASE!
*/

void	error_vm(char *s)
{
	ft_printf("%s\n", s);
	exit(EXIT_FAILURE);
}
