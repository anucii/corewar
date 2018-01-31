/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 18:11:19 by jgonthie          #+#    #+#             */
/*   Updated: 2018/01/31 20:03:44 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crack.h"

_Bool			write_header(int new_fd, int old_fd)
{
	char	name[PROG_NAME_LENGTH + 1];
	char	comment[COMMENT_LENGTH + 1];

	ft_bzero(name, PROG_NAME_LENGTH + 1);
	ft_bzero(comment, COMMENT_LENGTH + 1);
	lseek(old_fd, 4, SEEK_SET);
	read(old_fd, name, PROG_NAME_LENGTH);
	write(new_fd, ".name \"", 7);
	write(new_fd, name, ft_strlen(name));
	write(new_fd, "\"\n", 2);
	lseek(old_fd, PROG_NAME_LENGTH + 12, SEEK_SET);
	read(old_fd, comment, COMMENT_LENGTH);
	write(new_fd, ".comment \"", 10);
	write(new_fd, comment, ft_strlen(comment));
	write(new_fd, "\"\n", 2);
	return (1);
}
