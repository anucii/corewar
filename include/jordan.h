/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 19:15:51 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/27 17:35:33 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "../../mygit/libft/libft.h"
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
	char				op_code; //changed to char
	int					ocp;
	int					nb_param;
	int					pos; // 
}						t_order;

typedef struct			s_file
{
	char				*line;
	int					fd;
	int					ret;
}						t_file;

void		labelcall(t_order **champ, int fd, char *label, int pos);
int			deref_label(t_order **champ, char *label);
void		bigendian(unsigned int *i, unsigned short *s);
void		timetoatoi(unsigned int j, unsigned char c, char *param, int fd);
#endif
