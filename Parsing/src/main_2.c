#include "ft_multi_split.h"

int     main(int argc, char **argv)
{
	t_token **token;
	t_file	file;
	int     index;
	//    int     index_para;

	index = 0;
	if (argc != 2)
		ft_printf("Bad usage\n");
	else
	{
		token = ft_memalloc(sizeof(t_token*) * ft_count_line(argv[1]));
		file.fd = open(argv[1], O_RDONLY);
		if (file.fd == -1)
		{
			ft_printf("Ft. Open() Failed\n");
			return (0);
		}
		while ((file.ret = get_next_line(file.fd, &file.line)) == 1)
		{
			if (file.line[0] == HASH)
			{
				ft_strdel(&file.line);
				continue ;
			}
			token[index] = ft_memalloc(sizeof(t_token));
			if ((ft_multi_split_2(token[index], file)))
			{
				if (token[index]->type == INFO)
				{
					if (token[index]->info.type == NAME)
						ft_printf("%s\n", token[index]->info.name);
					else if (token[index]->info.type == COMMENT)
						ft_printf("%s\n", token[index]->info.comment);
				}
				/*
			   else if (token[index].type == LABEL)
			   {
				   index_para = 0;
				   ft_printf("Label name: %s\n", token[index].label.name);
				   ft_printf("OP_CODE: %d\n", token[index].label.op_code);
				   while (index_para < token[index].label.nb_params)
				   {
					   ft_printf("Params: %s\n", token[index].label.params[index_para]);
					   index_para++;
				   }
				}
				   */
			}
			ft_strdel(&file.line);
			index++;
		}
		if (file.ret == -1)
			ft_printf("Ft. Read() Failed\n");
	}
	while (1);
	return (0);
}
