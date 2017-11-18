#include "ft_multi_split.h"

static int  ft_stock_line(t_token ****token, char *s)
{
	int     index;

	index = 0;
	if ((***token)->info.type == NAME)
	{
		while (*s && *s != COTE)
		{
			(***token)->info.name[index] = *s;
			index++;
			s += 1;
		}
	}
	else
	{
		while (*s && *s != COTE)
		{
			(***token)->info.comment[index] = *s;
			index++;
			s += 1;
		}
	}
	return (0);
}

static int  ft_pars_line(t_token ***token, char *s, int size)
{
	int     len;

	len = 0;
	while (*s && (*s == SPACE || *s == TAB))
		s += 1;
	if (!(*s) || *s != COTE)
		return (0);
	s += 1;
	while (*s && *s != COTE && len < size)
	{
		s += 1;
		len++;
	}
	if (!(*s) || len == size || *(s + 1) != '\0')
		return (0);
	s -= len;
	ft_stock_line(&token, s);
	return (1);
}

int     ft_info_line(t_token **token, char *s)
{
	int     len;

	len = 0;
	while (*s && *s != SPACE && *s != TAB)
	{
		len++;
		s += 1;
	}
	s -= len;
	if (*(s + len + 1) && len == 5 && ft_strncmp(s, ".name", 5) == 0)
	{
		s += len;
		(*token)->info.type = NAME;
		if (!(ft_pars_line(&token, s, 129)))
			return (0);
	}
	else if (*(s + len + 1) && len == 8 && ft_strncmp(s, ".comment", 8) == 0)
	{
		s += len;
		(*token)->info.type = COMMENT;
		if (!(ft_pars_line(&token, s, 2047)))
			return (0);
	}
	else
		return (0);
	return (1);
}
