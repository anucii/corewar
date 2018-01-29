/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:24:23 by jdaufin           #+#    #+#             */
/*   Updated: 2018/01/26 14:02:27 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static _Bool	check_label(char **tokens, t_order *slot)
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

static char		get_code(char *s)
{
	char	i;

	if (!(s && ((i = op_matches(s)) >= 0)))
		return (0);
	return (g_op_tab[(int)i].op_code);
}

static _Bool	check_master(char **tokens, t_order *slot, ssize_t op_idx)
{
	char	code;
	_Bool	ret;

	if ((op_idx > 0) && !check_label(tokens, slot))
		return (0);
	if ((ret = (op_matches(tokens[op_idx])) >= 0))
	{
		code = get_code(tokens[op_idx]);
		slot->op_code = code;
	}
	return (ret);
}

static ssize_t	parse_master(char **tokens, int argnum)
{
	int i;

	i = -1;
	while (++i < argnum)
	{
		if (op_matches(tokens[i]) >= 0)
			return (i);
	}
	return (-1);
}

_Bool			parse_instr(char **tokens, int argnum, t_order *slot)
{
	int op_idx;

	if (!(tokens && *tokens && (argnum > 0) && (argnum <= I_MAXLEN)\
				&& slot))
	{
		ft_putendl_fd("[ERR] parse_instr : bad params", 2);
		exit(EXIT_FAILURE);
	}
	op_idx = parse_master(tokens, argnum);
	if ((op_idx == -1) && (argnum == 1))
		return (check_label(tokens, slot));
	else if ((op_idx == -1) || !check_master(tokens, slot, op_idx))
		return (0);
	return (pars_param(tokens, argnum, slot, op_idx));
}
