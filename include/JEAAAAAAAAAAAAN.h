/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 19:15:51 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/18 19:20:22 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "libft/libft.h"
# include <fcntl.h>

# define HASH			'#'
# define SPACE			' ' 
# define TAB			'\t'
# define DOT			'.'
# define COMMA			','
# define COTE			'\"'
# define COLON			':'

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
	int					fd;
	int					ret;
}						t_file;

int		ft_count_line(char *argv);
int		ft_is_label_char(char c, char *label_char);

#endif
