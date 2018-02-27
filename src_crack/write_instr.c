/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 19:46:39 by jgonthie          #+#    #+#             */
/*   Updated: 2018/02/27 14:30:06 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crack.h"

static int		check_op(unsigned char c)
{
	char			*conv_hexa;
	char			*conv_deci;
	int				op;

	conv_hexa = ft_strbase(c, "0123456789abcdef");
	conv_deci = ft_to_deci(conv_hexa, "0123456789abcdef");
	op = op_matches(conv_deci);
	ft_strdel(&conv_hexa);
	ft_strdel(&conv_deci);
	if (op == -1)
	{
		ft_printf("Error : Bad instr\n");
		return (-1);
	}
	return (op);
}

static _Bool	write_instr_in_file(unsigned char *s, int *index, int fd)
{
	int				info[2];
	int				instr;

	if ((instr = check_op(s[(*index)])) == -1)
		return (0);
	write(fd, g_op_tab[instr].name, ft_strlen(g_op_tab[instr].name));
	write(fd, " ", 1);
	info[0] = g_op_tab[instr].op_code - 1;
	info[1] = g_op_tab[instr].nb_param;
	if (g_op_tab[instr].op_code == 1)
		write_dir(s, index, fd);
	else
	{
		if (!f_all(s, info, index, fd))
			return (0);
	}
	write(fd, "\n", 1);
	return (1);
}

static _Bool	check_len_prog(int old_fd, unsigned int size[1],
		unsigned char instr[CHAMP_MAX_SIZE + 1], unsigned int *len)
{
	lseek(old_fd, COMMENT_LENGTH + 4, SEEK_CUR);
	read(old_fd, instr, size[0]);
	if ((*size + PROG_NAME_LENGTH + COMMENT_LENGTH + 16) !=\
		(*len = lseek(old_fd, 0, SEEK_END)))
	{
		ft_printf("Error : Diff between file size and header prog_size\n");
		return (0);
	}
	return (1);
}

static _Bool	check_prog(int old_fd, unsigned char instr[CHAMP_MAX_SIZE + 1],
		unsigned int *len)
{
	unsigned int	size[1];

	lseek(old_fd, 0, SEEK_SET);
	read(old_fd, size, 4);
	littleendian(&size[0]);
	if (*size != COREWAR_EXEC_MAGIC)
	{
		ft_printf("Error : Invalid header\n");
		return (0);
	}
	lseek(old_fd, PROG_NAME_LENGTH + 8, SEEK_SET);
	read(old_fd, size, 4);
	littleendian(&size[0]);
	if (*size > CHAMP_MAX_SIZE)
	{
		ft_printf("Error : Champ to big\n");
		return (0);
	}
	if (!check_len_prog(old_fd, size, instr, len))
		return (0);
	return (1);
}

_Bool			write_instr(int new_fd, int old_fd)
{
	unsigned char	instr[CHAMP_MAX_SIZE + 1];
	unsigned int	size[1];
	unsigned int	len;
	int				index;

	size[0] = 0;
	index = -1;
	ft_bzero(instr, CHAMP_MAX_SIZE + 1);
	if (!check_prog(old_fd, instr, &len))
		return (0);
	len = len - (PROG_NAME_LENGTH + COMMENT_LENGTH + 16);
	while (++index < (int)len)
		if (!write_instr_in_file(instr, &index, new_fd))
			return (0);
	return (1);
}
