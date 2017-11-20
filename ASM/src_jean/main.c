#include "JEAAAAAAAAAAAAN.h"

int		main(int argc, char **argv)
{
//	t_order	**order;
	t_file	file;
	int		size;

	if (argc != 2)
	{
		ft_printf("Bad usage\n");
		return (0);
	}
	size  = ft_count_line(argv[1]);
	ft_printf("%d\n", size);
	exit(0);
//	order = ft_memalloc(sizeof(t_order*) * ft_count_line(argv[1]));
	file.fd = open(argv[1], O_RDONLY);
	if (file.fd == -1)
	{
		ft_printf("Ft. Open() Failed\n");
		return (0);
	}
	while ((file.ret = get_next_line(file.fd, &file.line)) == 1)
	{
		
	}
	return (0);
}
