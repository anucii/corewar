#include "ft_multi_split.h"

int     main(int argc, char **argv)
{
	t_token	**token;
	t_file	file;
	int     count_words;
	int     index;

	token = NULL;
	count_words = 0;
	if (argc != 2)
		ft_printf("Bad usage\n");
	else
	{
		token = ft_memalloc(sizeof(t_token**) * ft_count_line(file, argv[1]));
		file.fd = open(argv[1], O_RDONLY);
		if (file.fd == -1)
		{
			ft_printf("Ft. Open() Failed\n");
			return (0);
		}
	 /*	while ((file.ret = get_next_line(file.fd, &file.line)) == 1)
		{
			if ((count_words = ft_multi_split(&token, file.line)) != 0)
			{
				ft_printf("count_words = %d: ", count_words);
				index = -1;
				while (++index < count_words)
				{
					if (index + 1 == count_words)
						ft_printf("[%s]\n", token[index]);
					else
						ft_printf("[%s] ", token[index]);
				}
			}
			ft_strdel(&file.line);
		} */
		if (file.ret == -1)
			ft_printf("Ft. Read() Failed\n");
		if ((file.ret = close(file.fd)) == -1)
			ft_printf("Ft. Close() Failed\n");
	}
	return (0);
}
