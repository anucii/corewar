/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:27:23 by jpallard          #+#    #+#             */
/*   Updated: 2017/11/24 18:25:08 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/jordan.h"
#include "../include/op.h"

/*
** convert little endian in big endian
*/

void	bigendian(unsigned int *i, short *s)
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

int		startup(t_header *file)
{
	int		fd;

	fd = open("test.cor", O_CREAT | O_WRONLY, 777);
	if (fd == -1)
		return (-1);
	bigendian(&file->magic, 0);
	write(fd, &file->magic, 4);
	write(fd, file->prog_name, 129);
	write(fd, file->comment, 2049);
	return(fd);
}

/*
**create an octet from the type of params, in test
*/

unsigned char	opcbit(int *params, int nb)
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
**write each instruction in prod
*/

void	writeinst(int fd, t_order **champ)
{
	int		i;
	char c;

	i = 0;
	while (i < nb_struct) //need to create in one of the struct
	{
		write (fd, &champ[i]->op_code, 1);
		if (champ[i]->op_code != 1 && champ[i]->op_code != 9
				&& champ[i]->op_code != 12 && champ[i]->op_code != 15)
		{
			c = opcbit(champ[i]->ty_param, champ[i]->nb_param);
			write(fd, &c, 1);
		}
	}
}

/*
** central fonction
*/

void	reception(t_header *file, t_order **champ)
{
	int		fd;
	int		nb;

	nb = 
	fd = startup(file);
	writeinst(fd, champ);
}

int main()
{
	t_order **champ;
	t_header *file;
//	char	**bcode;

	file = (t_header*)malloc(sizeof(t_header));
	file->magic = COREWAR_EXEC_MAGIC;
	ft_strcpy(file->prog_name, "zork");
	ft_strcpy(file->comment, "I M ALIVE");
	champ = (t_order**)malloc(sizeof(t_order) * 1);
	champ[0] = (t_order*)malloc(sizeof(t_order));
	champ[0]->op_code = 11;
	champ[0]->ocp = 1;
	champ[0]->ty_param[0] = 1;
	champ[0]->ty_param[1] = 2;
	champ[0]->ty_param[2] = 2;
	reception(file, champ);
	return (0);
}
