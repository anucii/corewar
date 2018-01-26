/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:38:38 by jpallard          #+#    #+#             */
/*   Updated: 2018/01/26 19:19:21 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	error(char *s)
{
	ft_printf("%s\n", s);
	exit(EXIT_FAILURE);
}

void	error_file(char *s)
{
	ft_printf("[ERR] : Invalidated data \"%s\"\n", s);
	exit(EXIT_FAILURE);
}

void	error_parsing(int n)
{
	ft_printf("[ERR] : parsing failure line [%d]\n", n + 3);
	exit(EXIT_FAILURE);
}

void	error_header(char *s)
{
	ft_printf(RED"%s\n"RESET, s);
}

void	error_param(char *s, char *failure)
{
	char	*tmp;
	int		index;
	int		index_fail;

	index = 0;
	index_fail = -1;
	tmp = ft_strstr(s, failure);
	ft_putchar('\"');
	while (s[index] != *tmp)
	{
		ft_printf("%c", s[index]);
		index++;
	}
	while (s[index] == failure[++index_fail] && failure[index_fail])
	{
		ft_printf(RED"%c"RESET, failure[index_fail]);
		index++;
	}
	while (s[index])
	{
		ft_printf("%c", s[index]);
		index++;
	}
	ft_putstr("\"\n");
}
