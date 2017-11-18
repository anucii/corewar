#include "ft_multi_split.h"
/*
static int	ft_check_op_code(t_token ***token, t_file file)
{
	int		len;

	len = 0;
	while ((file.ret = get_next_line(file.fd, &file.line)) == 1)
	{
		while (*file.line && (*file.line == SPACE || file.line == TAB))
			file.line += 1;
		if (!*file.line)
			return (0);
		while (*file.line && ft_is_label_char(*file.line, LABEL_CHAR))
		{
			file.line += 1;
			len++;
		}
		file.line -= len;
		if (*(file.line + len + 1) || ft_strncpy(file.line, "sti", len) == 0)
		{
			file.line += len;
			(**token)->type = LABEL;
			(**token)->label.op_code = 11;
		}
	}
	if (file.ret == -1)
		return (0);
	return (1);
	token = NULL;
}
*/
int		ft_info_label(t_token **token, t_file file)
{
	while (*file.line && ft_is_label_char(*file.line, LABEL_CHAR)
			&& *file.line != COLON && *file.line != SPACE && *file.line != TAB)
		file.line += 1;
	if (!*file.line || *file.line == TAB || *file.line == SPACE)
		return (0);
	if (*file.line == COLON)
	{
		file.line += 1;
		while (*file.line && (*file.line == TAB || *file.line == SPACE))
			file.line += 1;
	}
	if (!*file.line)
	{
//		if (!ft_check_op_code(&token, file))
//			return (0);
		ft_printf("end of line\n");
	}
	else
		ft_printf("params\n");
	return (1);
	token = NULL;
}
