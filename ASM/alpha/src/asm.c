#include "asm.h"

static void	init_hdr(t_header *hdr, char *s)
{
	char 	*tmp;
	int		fd;

	if (!(hdr && s))
		error("[ERR] : bad params to init header");
	hdr->magic = COREWAR_EXEC_MAGIC;
	if ((fd = open(s, O_RDONLY /*| O_SYMLINK*/)) < 0)
		error("[ERR] : opening failed on filepath");
	if (ft_strlen(s) > 250)
		error("[ERR] : FIle name to long (250 octet max)");
	tmp = ft_strsub(s, ft_strlen(s) - ft_strlen(ft_strrchr(s, DOT)), ft_strlen(s));
	if (ft_strcmp(tmp, ".s") != 0)
		error("Bad file name, so fuck you!");
	ft_strdel(&tmp);
	hdr->filename = ft_strdup(s);
	hdr->nb_struct = 0;
	hdr->prog_size = 0;
	if (close(fd) != 0)
		error("[ERR] : parsing file closing failed");
}

int     main(int argc, char **argv)
{
	t_order     **tab;
	t_header    hdr;

	tab = ft_memalloc(sizeof(t_order**) * (SIZE_STRUCT));
	if (argc < 2)
		error("Usage : ./parser <line content space-separated>");
	init_hdr(&hdr, argv[argc - 1]);
	if (!launch_parsing(argv[argc - 1], &tab, &hdr))
		error("[ERR] : parsing failure");
	calc_prog_size(tab, &hdr);
	writeinst(tab, &hdr);
	ft_strdel(&hdr.filename);
	free_order(tab, hdr.nb_struct);
	return (0);
}
