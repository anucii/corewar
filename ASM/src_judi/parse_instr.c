/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:24:23 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/23 22:35:35 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "judi.h"

static _Bool	check_label(char **tokens, t_order **slot)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(tokens[0]);
	if (tokens[0][len - 1] != LABEL_CHAR)
		return (0);
	i = 0;
	while (i < (len - 1))
	{
		if (!ft_strchr(LABEL_CHARS, tokens[0][i]))
			return (0);
		++i;
	}
	add_label(slot, tokens[0]);
	return (1);
}

static _Bool	check_master(char **tokens, t_order **slot, ssize_t op_idx)
{
	if ((op_idx > 0) && !check_label(tokens, slot))
		return (0);
	return (1);
}

static ssize_t	parse_master(char **tokens, int argnum)
{
	int	ret;
	int i;

	i = -1;
	while (++i < argnum)
	{
		if (op_matches(tokens[i]))
			return (i);
	}
	return (ret = -1);
}

_Bool			parse_instr(char **tokens, int argnum, t_order **slot)
{
	int op_idx;

	if (!(tokens && *tokens && (argnum > 0) && (argnum <= I_MAXLEN)\
				&& slot && *slot))
	{
		ft_putendl_fd("[ERR] parse_instr : bad params", 2);
		exit(EXIT_FAILURE);
	}
	op_idx = parse_master(tokens, argnum);
	if ((op_idx == -1) && (argnum == 1))
		return (check_label(tokens, slot));
	else if (op_idx != -1)
		if (!check_master(tokens, slot, op_idx))
			return (0);
	return (parse_params(tokens, argnum, slot, op_idx));
}
