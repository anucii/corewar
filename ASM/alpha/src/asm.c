#include "asm.h"

int     main(int argc, char **argv)
{
    t_order     **tab;
    t_header    hdr;

	tab = ft_memalloc(sizeof(t_order**) * (SIZE_STRUCT));
    if (argc < 2)
        error("Usage : ./parser <line content space-separated>");
    launch_parsing(argv[argc - 1], tab, &hdr);
	calc_prog_size(tab, &hdr);
	writeinst(tab, &hdr);
    return (0);
}
