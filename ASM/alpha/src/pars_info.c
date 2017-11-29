#include "asm.h"

static void    inc_line(char *line, int *index, int *len, int size)
{
	while (line[*index] && (line[*index] == SPACE || line[*index] == TAB))
		*index += 1;
	if (line[*index] && line[*index] == COTE)
	{
		while (line[++*index] && ((line[*index] < 127 && line[*index] > 34)
					|| line[*index] == SPACE || line[*index] == TAB
					|| line[*index] == '!') && *len < size)
			*len += 1;
	}
}

static int    comment_line(t_header *info, char *line, int index)
{
	int     len;

	len = 0;
	inc_line(line, &index, &len, COMMENT_LENGTH);
	ft_bzero(info->comment, COMMENT_LENGTH + 1);
	ft_strncpy(info->comment, ((const char*)line + index - len), len);
	while (line[++index])
	{
		if (line[index] != SPACE && line[index] != TAB)
		{
			if (line[index] == HASH)
				return (1);
			ft_bzero(info->comment, COMMENT_LENGTH + 1);
			return (0);
		}
	}
	return (1);
}

static int    name_line(t_header *info, char *line, int index)
{
	int     len;

	len = 0;
	inc_line(line, &index, &len, PROG_NAME_LENGTH);
	ft_bzero(info->prog_name, PROG_NAME_LENGTH + 1);
	ft_strncpy(info->prog_name, ((const char*)line + index - len), len);
	while (line[++index])
	{
		if (line[index] != SPACE && line[index] != TAB)
		{
			if (line[index] == HASH)
				return (1);
			ft_bzero(info->prog_name, PROG_NAME_LENGTH + 1);
			return (0);
		}
	}
	return (1);
}

_Bool             pars_info(t_header *info, char *line)
{
	int     index;
	int     len;

	index = 0;
	len = 1;
	while (line[index] && (line[index] == SPACE || line[index] == TAB))
		index++;
	if (line[index] && line[index] == DOT)
		while (line && is_label_char(line[++index], LABEL_CHARS))
			len++;
	if (len == 5 && ft_strncmp(((const char*)line + index - len), ".name", len) == 0)
	{
		if (!name_line(info, line, index))
			return (0);
	}
	if (len == 8 && ft_strncmp(((const char*)line + index - len), ".comment", len) == 0)
	{
		if (!comment_line(info,line, index))
			return (0);
	}
	return (1);
}
