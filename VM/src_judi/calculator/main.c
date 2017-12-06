#include "calc.h"

static void			init_proc(t_proc *ptr, ssize_t id)
{
	ssize_t	i = -1;

	if (!ptr)
		return ;
	ptr->pid = (short)id;
	ptr->pc = ptr->pid * (MEMSIZE / MAX_PROC);
	while (++i < REG_NUM)
		ptr->reg[i] = 0;
	ptr->carry = 0;
}

static t_proc		**init_procs(void)
{
	t_proc	**ret;
	ssize_t	i = -1;

	if (!(ret = malloc(sizeof(t_proc *) * MAX_PROC)))
		return (NULL);
	while (++i < MAX_PROC)
	{
		if (!(ret[i] = malloc(sizeof(t_proc))))
			return (NULL);
		init_proc(ret[i], i);
	}
	return (ret);
}

int		main(void)
{
	static t_proc	**procs;
	
	procs = init_procs();
	while (calc(procs))
		;
	return (0);
}
