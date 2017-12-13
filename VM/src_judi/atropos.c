/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atropos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:55:28 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/13 14:56:23 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "judi.h"

/*
**	Called when timer reaches CYCLE_TO_DIE, checks the life.status of each process
**	NB : a killed process
**	- gets its malloc'd fields freed
**	- gets freed itself
**	- is pulled off the list in a way that does not destroys the list itself
*/

void	kill_proc(t_proc **ptr_proc)
{
	t_proc	*record;

	if (!(ptr_proc && *ptr_proc))
		return ;
	record = (*ptr_proc)->children;
	if ((*ptr->proc)->life.status)
		return ;
	free(*ptr_proc);
	*ptr_proc = record;
}

void	atropos(t_proc **tab)
{
	if (!tab)
		return ;
	foreach_proc(tab, &kill_proc);
}

/*
** Maintest
*/
#include <stdlib.h>
#include <stdio.h>

static void		init_proc(t_proc **ptr, unsigned int depth)
{
	ssize_t	i = -1;

	if (!(ptr && (*ptr = (t_proc *)malloc(sizeof(t_proc)))))
		return ;
	(*ptr)->carry = 0;
	(*ptr)->life.status = 0;
	(*ptr)->life.last = depth;
	(*ptr)->life.player = 0;
	while (++i < REG_NUMBER)
		(*ptr)->reg[i] = (unsigned char)i;
	(*ptr)->pid = new_pid();
	(*ptr)->pc = 0;
	(*ptr)->cc = 0;
	(*ptr)->children = NULL;
	if (depth < 5)
		init_proc(&((*ptr)->children), depth + 1);
}

static void		make_list(t_proc **ptr)
{
	if (!ptr)
		return ;
	init_proc(ptr, 0);
	return ;
}

static void		gen_procs(t_proc **tab)
{
	ssize_t i = -1;
	
	while (++i < 4)
		make_list(&tab[i]);
}

int				main(void)
{
	ssize_t	i = -1;
	t_proc **tab = (t_proc **)malloc(sizeof(t_proc *) * 4);

	if (tab)
		gen_procs(tab);
	else
	{
		puts("Malloc failure on processes array initialization");
		exit(EXIT_FAILURE);
	}
	while (++i < 4)
	return (0);
}
