/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:08:38 by jgonthie          #+#    #+#             */
/*   Updated: 2017/09/25 17:47:47 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_word(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (*s)
	{
		if (*s == c)
			i = 0;
		if (*s != c && i == 0)
		{
			i = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static size_t	ft_word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nb_word;
	size_t	i;

	i = 0;
	tab = NULL;
	nb_word = 0;
	if (!s && !c)
		return (NULL);
	nb_word = ft_count_word(s, c);
	if (!(tab = (char**)malloc(sizeof(char**) * (nb_word + 1))))
	{
		ft_putstr("MALLOC FAILED\n");
		exit(0);
	}
	while (nb_word--)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[i] = ft_strsub(s, 0, ft_word_len(s, c));
		s += ft_word_len(s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
