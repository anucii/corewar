/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labelcall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:44:04 by jpallard          #+#    #+#             */
/*   Updated: 2018/02/08 18:29:16 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	void	write_max(char *param, unsigned char c, int fd)
{
	c = (char)(ft_atoi(param));
	write(fd, &c, 1);
}

void			timetoatoi(unsigned int j, unsigned char c, char *param, int fd)
{
	unsigned short s;

	if (c > 0)
		write_max(param, c, fd);
	else if (j > 0)
	{
		if (dir_as_addr(j) == 1)
		{
			s = (short)(ft_atoi(param));
			bigendian(0, &s);
			write(fd, &s, 2);
		}
		else
		{
			j = (unsigned int)(ft_atoi(param));
			bigendian(&j, 0);
			write(fd, &j, 4);
		}
	}
	else
	{
		s = (short)(ft_atoi(param));
		bigendian(0, &s);
		write(fd, &s, 2);
	}
}

static	void	label4(int fd, int res, unsigned int pos)
{
	unsigned int max;

	max = 0xFFFF;
	if (res < 0)
	{
		max = max + res + 1;
		bigendian(&max, 0);
		write(fd, &max, 4);
	}
	else
	{
		pos = res;
		bigendian(&pos, 0);
		write(fd, &pos, 4);
	}
}

void			labelcall(t_order **champ, int fd, char *label, t_order *inst)
{
	unsigned short	pos;
	short			res;
	unsigned short	max;

	pos = deref_label(champ, label);
	res = pos - inst->pos;
	max = 0xFFFF;
	if (dir_as_addr(inst->op_code) == 1 || str_t(0, 0) == T_IND || str_t(-1, 0))
	{
		if (res < 0)
		{
			max = max + res + 1;
			bigendian(0, &max);
			write(fd, &max, 2);
		}
		else
		{
			pos = res;
			bigendian(0, &pos);
			write(fd, &pos, 2);
		}
	}
	else
		label4(fd, (int)res, (unsigned int)pos);
}
