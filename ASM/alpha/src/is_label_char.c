/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_label_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:53:33 by jpallard          #+#    #+#             */
/*   Updated: 2017/12/04 16:53:37 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

_Bool			is_label_char(char c, char *label_char)
{
	while (*label_char)
	{
		if (c == *label_char)
			return (1);
		label_char += 1;
	}
	return (0);
}
