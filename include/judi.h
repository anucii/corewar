/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 19:15:51 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/24 19:07:38 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "libftprintf.h"
# include "libft.h"
# include <fcntl.h>

# define HASH			'#'
# define SPACE			' ' 
# define TAB			'\t'
# define DOT			'.'
# define COMMA			','
# define COTE			'\"'
# define COLON			':'
# define I_MAXLEN		5

/*
typedef struct			s_info
{
	char				name[129];
	char				comment[2047];
}						t_info;
*/

/*
**	The following structure stores, among other things:
**	- a series of label strings associated w/ the given instruction
**	- an array (ty_param) of the signatures of the parameters
**	- an int (pos) to store the Byte index of the instruction
**	- an int (size) to store the Byte size of the instruction
*/

typedef struct			s_order
{
	char				**label;
	char				**param;
	int					ty_param[3];
	char				op_code;
	int					nb_param;
	int					pos; 
	int					size;
}						t_order;

typedef struct			s_file
{
	char				*line;
	int					fd;
	int					ret;
}						t_file;

typedef struct			s_op
{
	char				*name;
	int					nb_param;
	int					tp_param[3];
	char				op_code;
	int					cycles;
	char				*description;
	_Bool				bool_1;
	_Bool				bool_2;
}						t_op;

_Bool					parse_instr(char **tokens, int argnum, t_order *slot);
_Bool					parse_params(char **tokens, int argnum, t_order *slot,\
	   ssize_t op_idx);
char					op_matches(char *s);
void					add_label(t_order *slot, char *s);

extern t_op				g_op_tab[17];

#endif
