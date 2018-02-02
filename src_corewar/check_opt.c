/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 12:27:24 by jgonthie          #+#    #+#             */
/*   Updated: 2018/02/02 15:09:46 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	check_curse(t_info *info)
{
	if (info->opt[3])
		error_vm(""RED"Error : Options -v and -c are incompatible"RESET"");
	if (info->opt[0])
		error_vm(""RED"Error : Option -c already given"RESET"");
	info->opt[0] = 1;
	info = ini_music(info);
}

void	check_verbos(t_info *info, char **arg, int *index)
{
	if (info->opt[0])
		error_vm(""RED"Error : Option -v and -c are incompatible"RESET"");
	if (info->opt[3])
		error_vm(""RED"Error : Option -v already given"RESET"");
	if (!arg[(*index) + 1])
		print_usage("Error : format of -v error");
	check_int(arg[(*index) + 1]);
	info->opt[3] = 1;
	if ((info->opt[4] = ft_atoi(arg[(*index) + 1])) < 0)
		print_usage("Error : Positive int Needed for opt -dump and -v");
	*index += 1;
}

void	check_dump(t_info *info, char **arg, int *index)
{
	if (info->opt[1])
		error_vm(""RED"Error : Option -dump already given"RESET"");
	if (!arg[(*index) + 1])
		print_usage("Error : format of -dump error");
	check_int(arg[(*index) + 1]);
	info->opt[1] = 1;
	if ((info->opt[2] = ft_atoi(arg[(*index) + 1])) < 0)
		print_usage("Error : Positive int Needed for opt -dump and -v");
	*index += 1;
}

void	check_id_player(t_info *info, char **arg, int *index, int id)
{
	if (id == -1)
		id = 0;
	else
		id++;
	if (!arg[(*index) + 1] || !arg[(*index) + 2])
		print_usage("Error : format of -n error");
	check_int(arg[(*index) + 1]);
	info->id_player[id] = ft_atoi(arg[(*index) + 1]);
	*index += 1;
}
