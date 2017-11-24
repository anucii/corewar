#include "JEAAAAAAAAAAAAN.h"

int		main(int argc, char **argv)
{
	t_order	**order;
	t_info	info;
	t_file	file;
	int		size;

	size = 1;
	if (argc != 2)
		ft_error("Bad usage\n");
	order = ft_memalloc(sizeof(t_order*) * SIZE_STRUCT * size);
	file.fd = open(argv[1], O_RDONLY);
	if (file.fd == -1)
		ft_error("Ft. Open() Failed\n");
	file.nb_line = -1;
	while ((file.ret = get_next_line(file.fd, &file.line)) == 1)
	{
		while (*file.line == SPACE || *file.line == TAB)
			file.line += 1;
		if (*file.line == '#' || *file.line == '\0')
			continue ;
		if (*file.line == DOT)
		{
			ft_pars_info(&info, file.line);
			ft_printf(".name = "RED"%s"RESET", .comment = "GREEN"%s"RESET"\n", info.name, info.comment);
			continue ;
		}
		if (++file.nb_line == SIZE_STRUCT * size)
			ft_realloc_order(order, &size);
		order[file.nb_line] = ft_memalloc(sizeof(t_order));
		ft_pars_order(order[file.nb_line], file);
	}
	return (0);
}
