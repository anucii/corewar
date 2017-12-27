/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 19:46:39 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/27 20:02:07 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crack.h"

static int		check_op(unsigned char c)
{
	char			*conv_hexa;
	char			*conv_deci;
	int				op;

	conv_hexa = ft_strbase(c, "0123456789abdef");
	conv_deci = ft_to_deci(conv_hexa, "0123456789abcdef");
	if ((op = op_matches(conv_deci)) == -1)
		error("Bad instr!\n");
	ft_strdel(&conv_hexa);
	ft_strdel(&conv_deci);
	return (op);
}

static int		write_instr_in_file(unsigned char *s, int fd)
{
	static t_pft	ft[16] = {&f_live, &f_ld, &f_st, &f_add, &f_sub, &f_and,
		&f_or, &f_xor, &f_zjmp, &f_ldi, &f_sti, &f_fork, &f_lld, &f_lldi,
		&f_fork, &f_aff};
	static int		index = -1;
	int				instr;
	int				i;

	instr = check_op(s[++index]);
	write(fd, g_op_tab[instr].name, ft_strlen(g_op_tab[instr].name));
	write(fd, " ", 1);
	i = g_op_tab[instr].op_code - 1;
	ft[i](s, &index, fd);
	return (g_op_tab[instr].nb_param + 3);
}

void			write_instr(int new_fd, int old_fd)
{
	unsigned char	instr[CHAMP_MAX_SIZE];
	unsigned int	size[1];
	unsigned int	len;

	ft_bzero(instr, CHAMP_MAX_SIZE);
	lseek(old_fd, PROG_NAME_LENGTH + 8, SEEK_SET);
	read(old_fd, size, 4);
	lseek(old_fd, COMMENT_LENGTH + 4, SEEK_CUR);
	read(old_fd, instr, size[0]);
	len = lseek(old_fd, 0, SEEK_END);
	len = len - (PROG_NAME_LENGTH + COMMENT_LENGTH + 16);
	while (len-- > 0)
		len -= write_instr_in_file(instr, new_fd);
	return ;
}
