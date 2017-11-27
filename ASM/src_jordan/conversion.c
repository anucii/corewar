/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:27:23 by jpallard          #+#    #+#             */
/*   Updated: 2017/11/27 17:44:47 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/jordan.h"
#include "../../include/op.h"

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

	fd = open("test.cor", O_CREAT | O_WRONLY, 777);
	if (fd == -1)
		return (-1);
	bigendian(&file->magic, 0);
	write(fd, &file->magic, 4);
	write(fd, file->prog_name, 129);
	write(fd, file->comment, 2049);
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

void					writeparams(t_order **champ, int fd, t_order *inst)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < inst->nb_param)
	{
		if (inst->ty_param[i] == 1)
			timetoatoi(0, 1, inst->param[i], fd);
		else if (inst->ty_param[i] == 2)
		{
			if (inst->param[i][j] == LABEL_CHAR)
				labelcall(champ, fd, inst->param[i], inst->pos);
			else
				timetoatoi(1, 0, inst->param[i], fd);
		}
		else if (inst->ty_param[i] == 4)
		{
			if (inst->param[i][j] == LABEL_CHAR)
				labelcall(champ, fd, inst->param[i], inst->pos);
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
	int		i;
	int		fd;
	char	c;

	i = 0;
	fd = startup(file);
	while (i < 2) //need to create nb_struct in one of the struct
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
}

	/* use to test
int main()
{
	t_order **champ;
	t_header *file;

	file = (t_header*)malloc(sizeof(t_header));
	file->magic = COREWAR_EXEC_MAGIC;
	ft_strcpy(file->prog_name, "zork");
	ft_strcpy(file->comment, "I M ALIVE");
	champ = (t_order**)malloc(sizeof(t_order) * 2);
	champ[0] = (t_order*)malloc(sizeof(t_order));
	champ[0]->param = (char**)malloc(sizeof(char*) * 3);
	champ[0]->op_code = 11;
	champ[0]->ocp = 1;
	champ[0]->ty_param[0] = 1;
	champ[0]->ty_param[1] = 4;
	champ[0]->ty_param[2] = 2;
	champ[0]->nb_param = 3;
	champ[0]->param[0] = "12";
	champ[0]->param[1] = "20";
	champ[0]->param[2] = "33";
	champ[0]->pos = 10;
	champ[0]->label = (char**)malloc(sizeof(char*) * 1);
	champ[0]->label[0] =":theworld";
	champ[1] = (t_order*)malloc(sizeof(t_order));
	champ[1]->param = (char**)malloc(sizeof(char*) * 3);
	champ[1]->op_code = 11;
	champ[1]->ocp = 1;
	champ[1]->ty_param[0] = 1;
	champ[1]->ty_param[1] = 4;
	champ[1]->ty_param[2] = 2;
	champ[1]->nb_param = 3;
	champ[1]->param[0] = "12";
	champ[1]->param[1] = ":theworld";
	champ[1]->param[2] = "33";
	champ[1]->pos = 15;
	writeinst(champ, file);
	return (0);
}
*/
