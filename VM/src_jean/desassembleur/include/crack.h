/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:33:12 by jdaufin           #+#    #+#             */
/*   Updated: 2018/01/04 15:07:04 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CRACK_H
# define CRACK_H

# include "op.h"
# include "./libft/include/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define COREWAR_EXEC_MAGIC	0xea83f3
# define PROG_NAME_LENGTH	(128)
# define COMMENT_LENGTH		(2048)
# define MEM_SIZE			(4*1024)
# define CHAMP_MAX_SIZE		(MEM_SIZE / 6)
# define REG_NUMBER			16

extern t_op			g_op_tab[17];

_Bool				parse_file(char **new_file, char *old_file);
void				print_output(char *file);
_Bool				parse_header(char *file, int fd);
void				littleendian(unsigned int *i);
_Bool				write_header(int fd_new, int fd_old);
_Bool				write_instr(int fd_new, int fd_old);
char				op_matches(char *s);
void				f_live(unsigned char *instr, int *index, int fd);
_Bool				f_all(unsigned char *instr, int info[2],\
		int *index, int fd);
char				*new_join(char *s, char *to_join);
char				*ft_to_deci(char *s, char *base);
char				*to_hexa(unsigned char c1, unsigned char c2);
_Bool				check_opc(int (*size)[3], char *opc, int instr,\
		int nb_params);
void				write_reg(unsigned char *instr, int *index, int fd);
void				write_ind(unsigned char *instr, int *index, int fd,\
		_Bool print);
void				write_dir(unsigned char *instr, int *index, int fd);
_Bool				close_files(char *old, char *new, int *fd_old,\
		int *fd_new);

#endif
