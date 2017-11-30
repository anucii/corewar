/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 14:49:20 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/30 15:04:00 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 19:15:51 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/30 11:33:32 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "./libft/include/libft.h"
# include <fcntl.h>

# define SIZE_STRUCT	20
# define HASH			'#'
# define SPACE			' '
# define TAB			'\t'
# define DOT			'.'
# define COMMA			','
# define COTE			'\"'
# define COLON			':'
# define I_MAXLEN		5

# define T_REG_SIZE		1
# define T_IND_SIZE		2
# define T_DIR_SIZE		4

/*
**	Global variable from op.c and its struct
*/

typedef struct			s_op
{
	char				*name;
	int					nb_param;
	int					tp_param[3];
	char				op_code;
	int					cycles;
	char				*description;
	_Bool				has_ocp;
	_Bool				bool_2;
}						t_op;

extern t_op 			g_op_tab[17];

/*
**	The following structure stores, among other things:
**	- a series of label strings associated w/ the given instruction
**	- an array (ty_param) of the signatures of the parameters
**	- an int (pos) to store the Byte index of the instruction
*/

typedef struct			s_order
{
	char				**label;
	char				**param;
	int					ty_param[3];
	int					nb_param;
	int					nb_label;
	char				op_code;
	short				pos;
	short				size;
}						t_order;

typedef struct			s_file
{
	char				*line;
	int					nb_line;
	int					fd;
	int					ret;
}						t_file;

_Bool					launch_parsing(char *filepath, t_order ***tab, t_header *hdr);
_Bool					pars_info(t_header *info, char *line);
_Bool					pars_order(t_order *order, t_file file);
_Bool					parse_instr(char **tokens, int argnum, t_order *slot);
_Bool					parse_params(char **tokens, int argnum, t_order *slot, ssize_t op_idx);
char					op_matches(char *s);
void					add_label(t_order *slot, char *s);
_Bool					is_label_char(char c, char *label_char);
_Bool					dir_param(char **param, int *ty_param, char *s);
_Bool					reg_param(char **param, int *ty_param, char *s);
_Bool					ind_param(char **param, int *ty_param, char *s);
_Bool					label_param(char *s);
_Bool					digit_param(char *s);
int						multi_split(char ***tokens, char *s);
void					error(char *s);
void					labelcall(t_order **champ, int fd, char *label, int pos);
int						deref_label(t_order **champ, char *label);
void					bigendian(unsigned int *i, unsigned short *s);
void					timetoatoi(unsigned int j, unsigned char c, char *param, int fd);
void					writeinst(t_order **champ, t_header *file);
void					calc_prog_size(t_order **champ, t_header *hdr);
void					free_order(t_order **tab, int size);
void					free_doublechar(char **tab, int size);

void					write_order_size(t_order *slot);
void					write_order_pos(t_order **tab, int last);
_Bool					has_ocp(char op_code);
_Bool					dir_as_addr(char op_code);

#endif
