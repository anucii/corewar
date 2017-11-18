#include "ft_multi_split.h"

static int	ft_check_if_instruction(char *s, int *check)
{
	static char	label[16][6] = {"live", "ld", "st", "add", "sub", "and",\
	   				"or", "xor", "zjmp", "ldi", "sti", "fork", "lld", \
					"lldi", "lfork", "aff"};
	static int	label_len[16] = {4, 2, 2, 3, 3, 3, 2, 3, 4, 3, 3, 4, 3, 4, 5, 3};
	char		*line;
	int			index;

	line = NULL;
	index = -1;
	while (*s && (*s == SPACE || *s == TAB))
		s += 1;
	if (*s && ft_is_label_char(*s, LABEL_CHAR))
	{
		while (++index < 16)
		{
			if (ft_strncmp(s, label[index], label_len[index]) == 0)
				return (1);
		}
	}
	*check = 1;
	return (0);
}

int			ft_count_line(char *arg)
{
	static int	check = 0;
	t_file		file;
	char		*tmp;
	int			count;

	tmp = NULL;
	count = 0;
	if ((file.fd = open(arg, O_RDONLY)) == -1)
	{
		ft_printf("Ft. Open() Failed\n");
		return (-1);
	}
	while ((file.ret = get_next_line(file.fd, &file.line)) == 1)
	{
		tmp = file.line;
		while (*tmp && (*tmp == SPACE || *tmp == TAB))
			tmp += 1;
		if (*tmp == DOT)
			count++;
		else if (ft_is_label_char(*tmp, LABEL_CHAR))
		{
			if (ft_check_if_instruction(tmp, &check))
			{
				if (check == 0)
					count++;
			}
			else
				count++;
		}
		else
			check = 0;
		ft_strdel(&file.line);
	}
	if (file.ret == -1)
	{
		ft_printf("Ft. Read() Failed\n");
		return (-1);
	}
	if ((file.ret = close(file.fd)) == -1)
	{
		ft_printf("Ft. Close() Failed\n");
		return (-1);
	}
	return (count);
}
