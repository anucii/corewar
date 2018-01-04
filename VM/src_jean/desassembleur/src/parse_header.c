/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 18:23:01 by jgonthie          #+#    #+#             */
/*   Updated: 2018/01/03 18:15:35 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crack.h"

_Bool			parse_header(char *file, int fd)
{
	unsigned int	i[1];
	unsigned int	len;
	unsigned int	j;

	read(fd, i, 4);
	littleendian(&i[0]);
	if ((len = lseek(fd, 0, SEEK_END)) < PROG_NAME_LENGTH +\
			COMMENT_LENGTH + 16 || *i != COREWAR_EXEC_MAGIC)
	{
		ft_printf("Error : <%s> has an invalid header (to small)\n", file);
		return (0);
	}
	lseek(fd, PROG_NAME_LENGTH + 8, SEEK_SET);
	read(fd, i, 4);
	littleendian(&i[0]);
	j = lseek(fd, 0, SEEK_END);
	if (*i + PROG_NAME_LENGTH + COMMENT_LENGTH + (sizeof(int) * 4) != j)
	{
		ft_printf("Error : Diff between file size and header prog_size");
		return (0);
	}
	return (1);
}
