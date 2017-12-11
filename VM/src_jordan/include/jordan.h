/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jordan.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:00:41 by jpallard          #+#    #+#             */
/*   Updated: 2017/12/11 18:12:50 by jpallard         ###   ########.fr       */
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
void			error_vm(char *s);
unsigned char	*load_champ(int *tab, short nb, t_proc **p);
void			littleendian(unsigned int *i);

#endif
