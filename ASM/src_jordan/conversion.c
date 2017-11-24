/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:27:23 by jpallard          #+#    #+#             */
/*   Updated: 2017/11/24 13:32:30 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/jordan.h"
#include "../include/op.h"
/*
char	*convertint(int opcode, char *binaire)
{
	const char *str;
	static int i = 0;

	str = "\0\1";
	i = 0;
	if (opcode >= 2)
		convertint(opcode/2, binaire);
		binaire[i++] = str[opcode % 2];
	return (binaire);
}*/

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

int		startup(t_header *file)
{
	int		fd;

	fd = open("test.cor", O_CREAT | O_WRONLY, 777);
	if (fd == -1)
		return ;
	bigendian(&file->magic, 0);
	write(fd, &file->magic, 4);
	write(fd, file->prog_name, 129);
	write(fd, file->comment, 2049);
	return(fd)
}

void	writeop&opc(fd, t_order **champ)
{
	write(fd, 

void	reception(t_header *file, t_order **champ)
{
	int		fd;
	int

	fd = startup(file);
	writeop(fd, champ);


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
