#include "calc.h"

static unsigned char	*memalloc(size_t size)
{
	unsigned char	*ret;
	ssize_t			i;

	if (!size)
		return (NULL);
	if (!(ret = malloc(sizeof(unsigned char) * size)))
		return (NULL);
	i = -1;
	while (++i < (ssize_t)size)
		ret[i] = 0;
	return (ret);
}

unsigned char			**memory(void)
{
	static _Bool			init = 0;
	static unsigned char	*mem;
	
	if (!init)
	{
		mem = memalloc(MEMSIZE);
		init = 1;
	}
	return (&mem);
}
