/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_vm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:52:38 by jpallard          #+#    #+#             */
/*   Updated: 2017/12/14 14:13:50 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "judi.h"

/*
**YOU REALLY NEED A COMMENT FOR THIS ONE !?
**YES PLEASE!
*/

void	error_vm(char *s)
{
	ft_printf("%s\n", s);
	exit(EXIT_FAILURE);
}
