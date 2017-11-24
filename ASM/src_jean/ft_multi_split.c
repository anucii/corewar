#include "JEAAAAAAAAAAAAN.h"

static int  ft_count_words(char *s)
{
	int     count;
	int     index;

	index = 0;
	count = 0;
	while (s[index] && (s[index] == SPACE || s[index] == TAB || s[index] == COMMA))
		index++;
	while (s[index])
	{
		if (s[index] && s[index] != SPACE && s[index] != TAB && s[index] != COMMA)
		{
			while (s[index + 1] && s[index] != SPACE && s[index] != TAB && s[index] != COMMA)
				index++;
			count++;
		}
		index++;
	}
	return (count);
}

static int  ft_word_len(char *s)
{
	int     len;

	len = 0;
	while (*s && *s != SPACE && *s != TAB && *s != COMMA)
	{
		len++;
		s += 1;
	}
	return (len);
}

int         ft_multi_split(char ***tokens, char *s)
{
	int     nb_words;
	int     index;
	int     count;
	int     len;

	count = -1;
	index = 0;
	if ((nb_words = ft_count_words(s)) == 0)
		return (nb_words);
	(*tokens) = ft_memalloc(sizeof(char**) * nb_words);
	while (++count < nb_words)
	{
		while (*s && (*s == SPACE || *s == TAB || *s == COMMA))
			s += 1;
		len = ft_word_len(s);
		(*tokens)[index] = ft_strsub(s, 0, len);
		s += ft_word_len(s);
		index++;
	}
	return (nb_words);
}
