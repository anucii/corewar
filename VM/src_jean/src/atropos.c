/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atropos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:55:28 by jdaufin           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/01/24 16:47:07 by jdaufin          ###   ########.fr       */
=======
/*   Updated: 2018/01/29 16:09:17 by jdaufin          ###   ########.fr       */
>>>>>>> db57eea64e3e
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Called when timer reaches CYCLE_TO_DIE, checks the life.status of each process
**	NB : a killed process
**	- gets its malloc'd fields freed
**	- gets freed itself
**	- is pulled off the list in a way that does not destroys the list itself
*/

void	kill_proc(t_proc **ptr_proc)
{
	t_info	*info;

	if (!(ptr_proc && *ptr_proc))
		return ;
	if ((global_timer(CHECK) - (*ptr_proc)->life.last) <= deadline(CHECK))
		return ;
	info = get_info(NULL);
	if (info->opt[3] && !info->opt[0])
		ft_printf("[DEATH (cy:%04u)]: Process %04u (player %d) hadn't lived \
for %u cycles (CTD: %d)\n", global_timer(CHECK), (*ptr_proc)->pid, \
(*ptr_proc)->champ.id, global_timer(CHECK) - (*ptr_proc)->life.last, \
deadline(CHECK));
<<<<<<< HEAD
	//if ((*ptr_proc)->champ.name)
	//	free((*ptr_proc)->champ.name); => sigabort error : freed object not allocated
	common_lst(DEL, *ptr_proc);
	free(*ptr_proc);
	*ptr_proc = record;
	kill_proc(ptr_proc);
=======
	proc_pop(proc_hdr(CHECK), *ptr_proc);
>>>>>>> db57eea64e3e
}

void	atropos(t_proc **p)
{
	if (!p)
		return ;
	foreach_proc(p, &kill_proc);
}

/*
** Maintest
#include <stdio.h>

static void		init_proc(t_proc **ptr, unsigned int player, unsigned int depth)
{
	ssize_t	i = -1;

	if (!(ptr && (*ptr = (t_proc *)malloc(sizeof(t_proc)))))
		return ;
	(*ptr)->carry = 0;
	(*ptr)->life.status = 0;
	(*ptr)->life.last = depth;
	(*ptr)->life.player = player;
	while (++i < REG_NUMBER)
		(*ptr)->reg[i] = (unsigned int)i;
	(*ptr)->pid = new_pid();
	(*ptr)->pc = 0;
	(*ptr)->cc = 0;
	(*ptr)->children = NULL;
	if (depth < 5)
		init_proc(&((*ptr)->children), player, depth + 1);
}

static void		make_list(t_proc **ptr, unsigned int player)
{
	if (!ptr)
		return ;
	init_proc(ptr, player, 0);
	return ;
}

static void		gen_procs(t_proc **tab)
{
	ssize_t i = -1;
	
	while (++i < 4)
		make_list(&tab[i], (unsigned int)i);
}

int				main(void)
{
	ssize_t	i;
	_Bool	alive;
	t_proc	*buf;
	t_proc	**tab = (t_proc **)malloc(sizeof(t_proc *) * 4);

	if (tab)
		gen_procs(tab);
	else
	{
		puts("Malloc failure on processes array initialization");
		exit(EXIT_FAILURE);
	}
	while (timer(CHECK) < 10)
	{
		i = -1;
		while (++i < 4)
		{
			buf = tab[i];
			while (buf)
			{
				alive = chronos(buf, i % 2 ? LIVE : CHECK, i); //sets alive only odd index processes
				printf("Player %zd (PID = %u) is %s.\n", i, buf->pid, alive ? "alive" : "dead");
				buf = buf->children;
			}
		}
		atropos(tab, 4);
		printf("Clock : %u\n", timer(INCR));
	}
	return (0);
}
*/
