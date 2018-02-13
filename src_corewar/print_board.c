/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 19:28:36 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/12 22:18:47 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Warning : don't be fooled by the metapointer in print_proc, it's used only
**	for compatibility purposes with the foreach_proc() function.
**	It is therefore only designed for printing one single process.
*/

void			print_proc(t_proc **p)
{
	t_info	*info;
	int		i;

	info = get_info(NULL);
	if (info->opt[0] || !info->opt[3] || !info->opt[4])
		return ;
	i = -1;
	ft_printf("[PROC_STAT (cy:%u)]: player %s(no %d), pid = %04u, pc = %04u,\
cc = %d, op_code: %d, carry:%s\n", global_timer(CHECK), (*p)->champ.name, \
(*p)->champ.id, (*p)->pid, (*p)->pc, (*p)->cc, (*p)->c_opc, (*p)->carry ? \
"TRUE" : "FALSE");
	ft_printf("> Registers:\n");
	while (++i < REG_NUMBER)
		ft_printf("[%d: 0x%08x(%d)]%c", i + 1, (*p)->reg[i], (*p)->reg[i],\
				(i + 1) % 8 ? ' ' : '\n');
	ft_printf("> Life status:\n");
	ft_printf(">> {%s, last_live: %u (life granted to player %d)}\n\n",\
			(*p)->life.status ? "Alive" : "Dead", (*p)->life.last,\
			(*p)->life.player);
}

/*
**	Warning : given the comparison with timer() output, it is important that
**	the print_board() function is being called before timer(REINIT) call in
**	the run() function;
*/

static _Bool	test_cycle(int period)
{
	if ((timer(CHECK) == deadline(CHECK)) || (period && !(global_timer(CHECK)\
					% period)))
		return (1);
	return (0);
}

static void		print_hdr(t_proc **tab)
{
	ft_printf("\n/* Periodic report */\n---------------------\n");
	ft_printf("Current round:\nCynum(rel.): %d\tCynum(abs.): %d\tLives: %u\t\
Processes: %d\n\n", timer(CHECK), global_timer(CHECK), nbr_live(CHECK),\
count_proc(tab));
}

void			print_board(t_proc **p, t_info *info)
{
	if (info->opt[0] || !info->opt[3] || !info->opt[4]\
			|| !test_cycle(info->opt[4]))
		return ;
	print_hdr(p);
	foreach_proc(p, &print_proc);
}
