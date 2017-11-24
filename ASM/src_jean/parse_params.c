/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:29:28 by jdaufin           #+#    #+#             */
/*   Updated: 2017/11/24 19:13:09 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "JEAAAAAAAAAAAAN.h"

//static void		ini_ty_param(t_order *slot, int index)

static _Bool	check_op(t_order *slot, char *s)
{
	static int	label_len[16] = {4, 2, 2, 3, 3, 3, 2, 3, 4, 3, 3, 4, 3, 4, 5, 3};
	int			index;

	index = -1;
	if (*s && ft_is_label_char(*s, LABEL_CHAR))
	{
		while (++index < 16)
		{
			if (ft_strncmp(s, g_op_tab[0][index], label_len[index]) == 0)
			{
				slot->nb_param = g_op_tab[3];
				return (ini_ty_param(slot, index);
			}
		}
	}
	return (0);
}

static _Bool	is_param(char *s, int nb_param)
{
	int		index;

	index = -1;
	while (s[index])
	{

	}
}

_Bool			parse_params(char **tokens, int max, t_order *slot, ssize_t op_idx)
{
	if (!(tokens && *tokens && (max > 0) && slot && *slot))
	{
		ft_putendl_fd("[ERR] parse_params: bad params", 2);
		exit(EXIT_FAILURE);
	}
	if (!check_op(slot, tokens[op_idx]))
		return (0);
	while (++op_idx < slot->nb_param)
		if (!(tokens[op_idx] || is_param(tokens[op_idx], slot->nb_param)))
			return (0);
	if (op_idx < max)
		if (tokens[op_idx][0] != '#')
			return (0);
	(slot->ty_param)[0] = T_DIR;
	(slot->ty_param)[1] = T_IND;
	(slot->ty_param)[2] = T_REG;
	return (1);
}
