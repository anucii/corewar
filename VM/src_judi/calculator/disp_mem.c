#include "calc.h"

void	disp_mem(unsigned char *mem)
{
	size_t	count[2] = {0,0};

	if (!mem)
		return ;
	while (count[1] < MEMSIZE)
	{
		count[0] = 0;
		while ((count[0] < 8) && ((count[1] + count[0]) < MEMSIZE))
		{
			printf("%4d%c", mem[count[1] + count[0]], count[0] < 7 ? ' ' : '\n');
			count[0]++;
		}
		count[1] += count[0];
	}
	printf("\n");
}
