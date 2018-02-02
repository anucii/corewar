/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:27:23 by jpallard          #+#    #+#             */
/*   Updated: 2018/02/02 15:46:48 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** convert little endian in big endian
*/

void					bigendian(unsigned int *i, unsigned short *s)
{
	if (i != 0)
	{
		*i = ((*i >> 24) & 0xff)
			| ((*i << 8) & 0xff0000)
			| ((*i >> 8) & 0xff00)
			| ((*i << 24) & 0xff000000);
	}
	if (s != 0)
		*s = (*s >> 8) | (*s << 8);
}

/*
** write magic number, name program and comment in that order
*/

static int				startup(t_header *file)
{
	int		fd;

	file->filename = new_name(file);
	fd = open(file->filename, O_CREAT | O_RDWR, 00770);
	if (fd == -1)
		return (-1);
	bigendian(&file->magic, 0);
	write(fd, &file->magic, 4);
	write(fd, file->prog_name, PROG_NAME_LENGTH + 4);
	bigendian(&file->prog_size, 0);
	write(fd, &file->prog_size, 4);
	write(fd, file->comment, COMMENT_LENGTH + 4);
	return (fd);
}

/*
**create an octet from the type of params
*/

static unsigned char	opcbit(int *params, int nb)
{
	unsigned char	a;
	unsigned char	b;
	unsigned char	c;
	unsigned char	d;
	int				i;

	a = 128;
	b = 192;
	c = 64;
	d = 0;
	i = 0;
	while (i < nb)
	{
		if (params[i] == 1)
			d = d | c;
		else if (params[i] == 2)
			d = d | a;
		else if (params[i] == 4)
			d = d | b;
		i++;
		a = a >> 2;
		b = b >> 2;
		c = c >> 2;
	}
	return (d);
}

/*
**write params in bytecode
*/

static void				writeparams(t_order **champ, int fd, t_order *inst)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < inst->nb_param)
	{
		if (inst->ty_param[i] == 1)
			timetoatoi(0, 1, inst->param[i], fd);
		else if (inst->ty_param[i] == 2 && str_t(1, T_DIR))
		{
			if (inst->param[i][j] == LABEL_CHAR)
				labelcall(champ, fd, inst->param[i], inst);
			else
				timetoatoi(inst->op_code, 0, inst->param[i], fd);
		}
		else if (inst->ty_param[i] == 4 && str_t(1, T_IND))
		{
			if (inst->param[i][j] == LABEL_CHAR)
				labelcall(champ, fd, inst->param[i], inst);
			else
				timetoatoi(0, 0, inst->param[i], fd);
		}
		i++;
	}
}

/*
**write each instruction in prod, need nb_struct in param
*/

void					writeinst(t_order **champ, t_header *file)
{
	unsigned int	i;
	int				fd;
	char			c;

	i = 0;
	if ((fd = startup(file)) == -1)
		error("[ERR] : bad filedescriptor");
	while (i < file->nb_struct)
	{
		write(fd, &champ[i]->op_code, 1);
		if (champ[i]->op_code != 1 && champ[i]->op_code != 9
				&& champ[i]->op_code != 12 && champ[i]->op_code != 15)
		{
			c = opcbit(champ[i]->ty_param, champ[i]->nb_param);
			write(fd, &c, 1);
		}
		writeparams(champ, fd, champ[i]);
		i++;
	}
	if (close(fd) != 0)
		error("[ERR] : Fildes closing failed");
}
