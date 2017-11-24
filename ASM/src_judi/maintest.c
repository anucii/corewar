#include "judi.h"

static void		disp(t_order *order)
{
	int	fd;
	int val = 255;

	if (!order)
	{
		ft_putendl_fd("Error : void t_order pointer", 2);
		exit(EXIT_FAILURE);
	}
	if ((fd = open("raw_instr", O_RDWR | O_CREAT | O_APPEND, 00660)) < 0)
	{
		ft_putendl_fd("File opening error", 2);
		exit(EXIT_FAILURE);
	}
	write(fd, order, sizeof(t_order));
	write(fd, &val, sizeof(short));
	close(fd);
}

static _Bool	t_parse(char **tokens, int max)
{
	//t_order	*order = (t_order [1]){{NULL, NULL,{0, 0, 0}, -1, 0, 0, 0}};
	t_order	order = {NULL, NULL,{0, 0, 0}, -1, 0, 0, 0};
	_Bool	ret;

	if (!(tokens && *tokens))
		return (0);
	ret = parse_instr(tokens, max, &order);
	if (ret)
		disp(&order);
	return (ret);
}

int		main(int ac, char **av)
{
	char	*result;

	if (ac < 2)
	{
		ft_printf("Usage : ./parser <line content space-separated>");
		return (-1);
	}
	result = t_parse(&av[1], ac - 1) ? "OK" : "KO";
	ft_printf("%s\n", result);
	return (0);
}
