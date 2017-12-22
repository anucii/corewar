/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 10:11:04 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/14 11:11:01 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	destroy_win(t_win *window)
{
	wborder(window->win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(window->win);
	delwin(window->win);
}