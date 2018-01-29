/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 14:52:12 by jgonthie          #+#    #+#             */
/*   Updated: 2018/01/26 10:53:57 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

_Bool	pars_order(t_order *order, char *s)
{
	char	**tokens;
	int		count_words;

	tokens = NULL;
	if ((count_words = multi_split(&tokens, s)) == 0)
		return (0);
	if (!(parse_instr(tokens, count_words, order)))
	{
		free_doublechar(tokens, count_words);
		return (0);
	}
	if (order->op_code)
		write_order_size(order);
	free_doublechar(tokens, count_words);
	return (1);
}
