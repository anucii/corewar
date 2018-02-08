/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:00:13 by jpallard          #+#    #+#             */
/*   Updated: 2018/02/08 14:17:02 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			littleendian(unsigned int *i)
{
	if (i != 0)
	{
		*i = ((*i >> 24) & 0xff)
			| ((*i << 8) & 0xff0000)
			| ((*i >> 8) & 0xff00)
			| ((*i << 24) & 0xff000000);
	}
}

static char		*get_name(int fd)
{
	char	name[PROG_NAME_LENGTH + 1];

	ft_bzero(name, PROG_NAME_LENGTH + 1);
	lseek(fd, 4, SEEK_SET);
	read(fd, name, PROG_NAME_LENGTH);
	return (store_names(INCR, ft_strdup(name)));
}

static void		init_proc(t_proc **p, t_info *info, int fd)
{
	static int	color = 1;
	static int	index = -1;
	t_proc		*new;

	new = ft_memalloc(sizeof(t_proc));
	new->color = color;
	new->carry = 0;
	new->pc = 0;
	new->cc = 0;
	new->c_opc = -1;
	new->pid = get_pid(INCR);
	new->champ.id = info->id_player[++index];
	new->reg[0] = new->champ.id;
	new->next = NULL;
	new->champ.name = get_name(fd);
	proc_add(p, new);
	color++;
}

/*
**	check if each champ have the correct header attached to them and if the size
**	is correct
*/

void			parse_header(int fd, t_proc **p, t_info *info)
{
	unsigned int	i[1];
	unsigned int	j;

	read(fd, i, 4);
	littleendian(&i[0]);
	if (*i != COREWAR_EXEC_MAGIC)
	{
		ft_printf("Error : %s has an invalid header", info->name);
		error_vm("");
	}
	init_proc(p, info, fd);
	lseek(fd, PROG_NAME_LENGTH + 8, SEEK_SET);
	read(fd, i, 4);
	littleendian(&i[0]);
	if (*i > CHAMP_MAX_SIZE)
		error_vm("Error : Champ too big");
	else if (*i <= 0)
		error_vm("Error : Champ size is 0 or negative ?");
	j = lseek(fd, 0, SEEK_END);
	if (*i + PROG_NAME_LENGTH + COMMENT_LENGTH + (sizeof(int) * 4) != j)
		error_vm("Error : Diff between file size and header prog_size");
}
