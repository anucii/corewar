#include "calc.h"

static _Bool	load_program(unsigned char **pmem)
{
	ssize_t			i = -1;
	/*
	unsigned char	prog[] = {\
		1, 1, 1,\
			1, 2, 2,\
			2, 1, 2, 3,\
			3, 1, 11,\
			3, 2, 8,\
			3, 3, 3,\
			3, 1, 3,\
			0\
	};*/
	unsigned char	prog[] = {\
		1, 3, 1,\
			1, 1, 2,\
			1, 3, 3,\
			3, 1, 9,\
			3, 2, 7,\
			3, 3, 5,\
			0\
	};

	/*
	 * Program's content : 
	 * store(3, reg_1)
	 * store(1, reg_2)
	 * store(3, reg_3)
	 * write(reg_1, @ pc + 9)
	 * write(reg_2, @ pc + 7)
	 * write(reg_3, @ pc + 5)
	 */

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
