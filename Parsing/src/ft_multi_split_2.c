#include "ft_multi_split.h"

int         ft_multi_split_2(t_token *token, t_file file)
{
    while (*file.line && (*file.line == SPACE || *file.line == TAB))
        file.line += 1;
    if (*file.line && *file.line == DOT)
    {
        (*token).type = INFO;
        if (!ft_info_line(&token, file.line))
            return (0);
    }
    else if (ft_is_label_char(*file.line, LABEL_CHAR))
    {
        (*token).type = LABEL;
       	if (!ft_info_label(&token, file))
           	return (0);
    }
    else
	 	return (0);
    return (1);
}
