/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JEAAAAAAAAAAAAN.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 19:15:51 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/27 17:50:10 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JEAAAAAAAAAAAAN_H
# define JEAAAAAAAAAAAAN_H

# include "op.h"
# include "libft/libft.h"
# include <fcntl.h>

# define SIZE_STRUCT	20

# define HASH			'#'
# define SPACE			' '
# define TAB			'\t'
# define DOT			'.'
# define COMMA			','
# define COTE			'\"'
# define COLON			':'

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

extern t_op 			g_op_tab[17];

typedef struct			s_info
{
	char				name[129];
	char				comment[2047];
}						t_info;

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
	int					op_code;
	int					nb_param;
	int					pos;
}						t_order;

typedef struct			s_file
{
	char				*line;
	int					nb_line;
	int					fd;
	int					ret;
}						t_file;

void					ft_error(char *s);
void					ft_realloc_order(t_order **order, int *size);
_Bool					ft_pars_order(t_order *order, t_file file);
_Bool					ft_pars_info(t_info *info, char *line);
_Bool					ft_is_label_char(char c, char *label_char);
int						ft_multi_split(char ***tokens, char *s);
_Bool					parse_params(char **tokens, int max, t_order *slot, ssize_t op_idx);
_Bool					dir_param(char **param, int *ty_param, char *s);
_Bool					reg_param(char **param, int *ty_param, char *s);
_Bool					ind_param(char **param, int *ty_param, char *s);
_Bool					label_param(char *s);
_Bool					digit_param(char *s);


#endif
