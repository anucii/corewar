/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 14:52:12 by jgonthie          #+#    #+#             */
/*   Updated: 2017/11/30 18:44:33 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
/*
static void put_tab(char *s)
{
	char	**tab;
	int		count_words;
	int     index;

	if ((count_words = multi_split(&tab, s)) != 0)
	{
		ft_printf("count_words = %d: ", count_words);
		index = -1;
		while (++index < count_words)
		{
			if (index + 1 == count_words)
				ft_printf("[%s]\n", tab[index]);
			else
				ft_printf("[%s] ", tab[index]);
		}
	}
}
*/
_Bool    pars_order(t_order *order, char *s)
{
	char    **tokens;
	int     count_words;

	tokens = NULL;
//	put_tab(s);
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
//	ft_printf("C'est de la merde = %s\n", order->label[0]);
	return (1);
}
