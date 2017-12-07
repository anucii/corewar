/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jordan.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:00:41 by jpallard          #+#    #+#             */
/*   Updated: 2017/12/07 17:59:55 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JORDAN_H
# define JORDAN_H

# include "./op.h"
# include "./libft/libft.h"
# include <fcntl.h>

void	checkheader(int fd);
void	error_vm(char *s);
char	*load_champ(int *tab, short nb);
void	littleendian(unsigned int *i);
#endif
