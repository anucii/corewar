/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:48:55 by jpallard          #+#    #+#             */
/*   Updated: 2017/12/04 16:50:56 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	int	count_words(char *s)
{
	int		count;
	int		index;

	index = 0;
	count = 0;
	while (s[index] && (s[index] == SPACE || s[index] == TAB || \
		s[index] == COMMA))
		index++;
	while (s[index])
	{
		if (s[index] && s[index] == HASH)
			return (count);
		if (s[index] && s[index] != SPACE && s[index] != TAB && \
			s[index] != COMMA)
		{
			while (s[index + 1] && s[index] != SPACE && s[index] != TAB && \
				s[index] != COMMA)
				index++;
			count++;
		}
		index++;
	}
	return (count);
}

static	int	word_len(char *s)
{
	int		len;

	len = 0;
	while (*s && *s != SPACE && *s != TAB && *s != COMMA)
	{
		len++;
		s += 1;
	}
	return (len);
}

int			multi_split(char ***tokens, char *s)
{
	int		nb_words;
	int		index;
	int		count;
	int		len;

	count = -1;
	index = 0;
	if ((nb_words = count_words(s)) == 0)
		return (nb_words);
	(*tokens) = ft_memalloc(sizeof(char**) * nb_words);
	while (++count < nb_words)
	{
		while (*s && (*s == SPACE || *s == TAB || *s == COMMA))
			s += 1;
		len = word_len(s);
		(*tokens)[index] = ft_strsub(s, 0, len);
		s += word_len(s);
		index++;
	}
	return (nb_words);
}
