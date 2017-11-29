#include "asm.h"

static void	init_hdr(t_header *hdr, char *s)
{
	if (!(hdr && s))
		error("[ERR] : bad params to init header");
	hdr->magic = COREWAR_EXEC_MAGIC;
	hdr->filename = ft_strdup(s);
	hdr->nb_struct = 0;
	hdr->prog_size = 0;
}

int     main(int argc, char **argv)
{
    t_order     **tab;
    t_header    hdr;

	tab = ft_memalloc(sizeof(t_order**) * (SIZE_STRUCT));
    if (argc < 2)
        error("Usage : ./parser <line content space-separated>");
	init_hdr(&hdr, argv[argc - 1]);
    if (!launch_parsing(argv[argc - 1], tab, &hdr))
		error("[ERR] : parsing failure");
	calc_prog_size(tab, &hdr);
	writeinst(tab, &hdr);
	ft_strdel(&hdr.filename);
	//free_tab(&tab);
    return (0);
}
