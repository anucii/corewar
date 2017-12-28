/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 19:46:39 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/28 18:40:18 by jgonthie         ###   ########.fr       */
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
	if ((op = op_matches(conv_deci)) == -1)
		error("Bad instr!");
	ft_strdel(&conv_hexa);
	ft_strdel(&conv_deci);
	return (op);
}

static void		write_instr_in_file(unsigned char *s, int *index, int fd)
{
	int				info[2];
	int				instr;
	int				i;

	instr = check_op(s[++(*index)]);
	write(fd, g_op_tab[instr].name, ft_strlen(g_op_tab[instr].name));
	write(fd, " ", 1);
	i = g_op_tab[instr].op_code - 1;
	info[0] = g_op_tab[instr].op_code - 1;
	info[1] = g_op_tab[instr].nb_param;
	if (g_op_tab[instr].op_code == 1)
		write_dir(s, index, fd);
	else if (g_op_tab[instr].op_code == 9 || g_op_tab[instr].op_code == 12)
		write_ind(s, index, fd, 1);
	else
		f_all(s, info, index, fd);
	write(fd, "\n", 1);
}

void			write_instr(int new_fd, int old_fd)
{
	unsigned char	instr[CHAMP_MAX_SIZE];
	unsigned int	size[1];
	unsigned int	len;
	int				index;
   
	index = -1;
	ft_bzero(instr, CHAMP_MAX_SIZE);
	lseek(old_fd, PROG_NAME_LENGTH + 8, SEEK_SET);
	read(old_fd, size, 4);
	lseek(old_fd, COMMENT_LENGTH + 4, SEEK_CUR);
	read(old_fd, instr, size[0]);
	len = lseek(old_fd, 0, SEEK_END);
	len = len - (PROG_NAME_LENGTH + COMMENT_LENGTH + 16);
	while (index < (int)len - 1)
		write_instr_in_file(instr, &index, new_fd);
}
