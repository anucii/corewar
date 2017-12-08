/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jordan.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:00:41 by jpallard          #+#    #+#             */
/*   Updated: 2017/12/08 17:38:44 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JORDAN_H
# define JORDAN_H

# include "./op.h"
# include "./libft/libft.h"
# include <fcntl.h>

void			checkheader(int fd);
void			error_vm(char *s);
unsigned char	*load_champ(int *tab, short nb);
void			littleendian(unsigned int *i);

#endif
