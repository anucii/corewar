/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jordan.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:00:41 by jpallard          #+#    #+#             */
/*   Updated: 2017/12/18 15:26:12 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JORDAN_H
# define JORDAN_H

# include "./op.h"
# include "./libft/libft.h"
# include <fcntl.h>

typedef struct			s_proc
{
	_Bool				carry;
	unsigned int		reg[REG_NUMBER];
	unsigned int		pc;
	char				*name;
	struct s_proc		*children;
}						t_proc;

void			checkheader(int fd, t_proc **p);
int				*checkocp(unsigned char *mem);
void			error_vm(char *s);
unsigned char	*load_champ(int *tab, short nb, t_proc **p);
void			littleendian(unsigned int *i);
void			int_on_mem(unsigned char *mem, unsigned int i, unsigned short s);
unsigned int	param_size(unsigned int p_first, int *params, _Bool dir_as_add,
							unsigned int (*p_idx)[3]);
unsigned int	convert(unsigned char *mem, unsigned int idx[3], int *p, int j);

#endif
