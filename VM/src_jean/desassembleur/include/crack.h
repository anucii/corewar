/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:33:12 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/22 17:16:21 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CRACK_H
# define CRACK_H

# include "op.h"
# include "./libft/include/libft.h"
# include <fcntl.h>

# define COREWAR_EXEC_MAGIC	0xea83f3
# define PROG_NAME_LENGTH	(128)
# define COMMENT_LENGTH		(2048)
# define MEM_SIZE			(4*1024)
# define CHAMP_MAX_SIZE		(MEM_SIZE / 6)
# define REG_NUMBER			16

extern t_op			g_op_tab[17];
typedef void		(*t_pft)(unsigned char *instr, int *index, int nb_param);

void				error(char *s);
_Bool				parse_file(char **new_file, char *old_file);
void				print_output(char *file);
_Bool				parse_header(char *file, int fd);
void				littleendian(unsigned int *i);
void				write_header(int fd_new, int fd_old);
void				write_instr(int fd_new, int fd_old);
char				op_matches(char *s);
void				f_live(unsigned char *instr, int *index, int fd);
void				f_ld(unsigned char *instr, int *index, int fd);
void				f_st(unsigned char *instr, int *index, int fd);
void				f_add(unsigned char *instr, int *index, int fd);
void				f_sub(unsigned char *instr, int *index, int fd);
void				f_and(unsigned char *instr, int *index, int fd);
void				f_or(unsigned char *instr, int *index, int fd);
void				f_xor(unsigned char *instr, int *index, int fd);
void				f_zjmp(unsigned char *instr, int *index, int fd);
void				f_ldi(unsigned char *instr, int *index, int fd);
void				f_sti(unsigned char *instr, int *index, int fd);
void				f_fork(unsigned char *instr, int *index, int fd);
void				f_lld(unsigned char *instr, int *index, int fd);
void				f_lldi(unsigned char *instr, int *index, int fd);
void				f_lfork(unsigned char *instr, int *index, int fd);
void				f_aff(unsigned char *instr, int *index, int fd);

#endif
