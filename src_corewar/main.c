/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 14:54:08 by jgonthie          #+#    #+#             */
/*   Updated: 2018/01/29 18:12:28 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				main(int argc, char **argv)
{
	t_proc			**p;
	t_info			*info;
	unsigned char	*arena;

	arena = NULL;
	if (!(p = proc_hdr(HDR_INIT)))
		error_vm("Proc_list header malloc failed");
	info = check_arg(p, &arena, argv, argc);
	get_info(&info);
	if (!info->opt[0])
		intr_msg(p);
	run(arena, p);
	if (info->opt[0])
	{
		destroy_win(info);
		endwin();
	}
	lives_reg(CHECK, 0, info, NULL);
	return (0);
}