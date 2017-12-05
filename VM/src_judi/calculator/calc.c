#include "calc.h"

static _Bool	load_program(unsigned char **pmem)
{
	ssize_t			i = -1;
	unsigned char	prog[] = {\
		1, 1, 1,\
			1, 2, 2,\
			2, 1, 2, 3,\
			3, 1, 11,\
			3, 2, 8,\
			3, 3, 3,\
			3, 1, 3,\
			0\
	};

	if (!(pmem && *pmem))
		return (0);
	while (prog[++i] && (i < MEMSIZE))
		(*pmem)[i] = prog[i];
	return (1);
}

_Bool	cycle(unsigned char **mem, t_proc **procs)
{
	_Bool	ret = 0;
	ssize_t	i = -1;

	if (!(mem && *mem && procs && *procs))
	{
		printf("Error : cycle received flawed params\n");
		exit(EXIT_FAILURE);
	}
	while (++i < MAX_PROC)
		ret |= execute(*mem, procs[i]);
	return (ret);
}

_Bool	calc(t_proc **procs)
{
	_Bool			ret;
	unsigned char	**mem = memory();

	if (!(procs && *procs && mem && *mem))
	{
		printf("Error : no %s\n", mem && *mem ? "processes" : "mem");
		return (0);
	}
	printf("Initial memory state :\n");
	disp_mem(*mem);
	printf("----------------------\n");
	if (!load_program(mem))
	{
		printf("Error : program loading failed\n");
		return (0);
	}
	disp_mem(*mem);
	while ((ret = cycle(mem, procs)))
		disp_mem(*mem);
	return (ret);
}
